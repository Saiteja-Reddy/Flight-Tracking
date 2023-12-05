//
// Created by Dylan Rose on 11/29/23.
//

#include "ADSBlolRESTClient.h"
#include <format>
#include <utility>

using namespace web;
using namespace web::http;

ADSBlolRESTClient::ADSBlolRESTClient() :
        base_uri("https://api.adsb.lol"),
        builder("/v2"),
        client(base_uri),
        targets(),
        currentStates()
{
    client = client::http_client(base_uri);
}

ADSBlolRESTClient::ADSBlolRESTClient(std::vector<std::string> input_targets) :
        base_uri("https://api.adsb.lol"),
        builder("/v2"),
        client(base_uri),
        targets(std::move(input_targets)),
        currentStates()
{
    client = client::http_client(base_uri);
}

void ADSBlolRESTClient::display_json(json::value const & jvalue)
{
    std::cout << jvalue.serialize() << std::endl;
}

std::vector<FlightStatusEvent> ADSBlolRESTClient::find_and_update_deltas(const std::vector<FlightStatusEvent>& all_events) {
    std::vector<FlightStatusEvent> updated_events{};
    for (const FlightStatusEvent& event : all_events) {
        const std::string& icao24 = event.getIcao24();
        bool no_change = (currentStates.count(icao24) && event == currentStates[icao24]);
        if (!no_change) {
            currentStates[icao24] = event;
            updated_events.push_back(event);
        }
    }
    return updated_events;
}

std::vector<FlightStatusEvent> ADSBlolRESTClient::make_request(const http_request& request) {
    std::vector<FlightStatusEvent> all_events{};
    client.request(request)
        .then([this](const http_response& response)
              {
                  json::value json_resp{json::value::null()};
                  try {
                      if (response.status_code() == status_codes::OK) {
                          json_resp = response.extract_json().get()["ac"];
                      } else {
                          throw http_exception("Not 200 resp");
                      }
                  } catch (http_exception& e) {
                      std::cout << e.what() << std::endl;
                  }
                  return json_resp;
              })
        .then([&all_events](web::json::value eventStates)
              {
                  if(!eventStates.is_null()) {
                      for (auto &item: eventStates.as_array()) {
                          try {
                              FlightStatusEvent e(item);
                              all_events.push_back(e);
                          } catch (http_exception& e) {
                              std::cout << e.error_code().message() << std::endl;
                          }
                      }
                  }
              })
        .wait();
    return all_events;
}

std::vector<FlightStatusEvent> ADSBlolRESTClient::get_events()
{
    std::vector<FlightStatusEvent> all_events{};

    http_request request(methods::GET);
    request.headers().add("accept", "application/json");
    auto tmp_builder = builder;

    if(targets.empty()) {
        tmp_builder.append("/point/40.712776/-74.005974/250");
        request.set_request_uri(tmp_builder.to_string());
        all_events = make_request(request);
    } else {
        for(const auto& target : targets) {
            tmp_builder = builder;
            tmp_builder.append("/icao/" + target);
            request.set_request_uri(tmp_builder.to_string());
            FlightStatusEvent single_event = make_request(request)[0];
            all_events.push_back(single_event);
        }
    }

    std::vector<FlightStatusEvent> updates = find_and_update_deltas(all_events);
    return updates;
}
