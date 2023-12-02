//
// Created by Dylan Rose on 11/29/23.
//

#include "OpenSkyRESTClient.h"

using namespace web;
using namespace web::http;

OpenSkyRESTClient::OpenSkyRESTClient() :
        base_uri("https://opensky-network.org/"),
        builder("/api/states/all"),
        client(base_uri),
        targets(),
        currentStates()
{
    // TODO: Put this into a config file
    client::credentials cred("drose2011", "C++InDesign");
    client::http_client_config config{};
    config.set_credentials(cred);

    // TODO: Don't make this class twice
    client = client::http_client(base_uri, config);

    builder.append_query("extended", "1");
}

OpenSkyRESTClient::OpenSkyRESTClient(std::vector<std::string> input_targets) :
        base_uri("https://opensky-network.org/"),
        builder("/api/states/all"),
        client(base_uri),
        targets(input_targets),
        currentStates()
{
    // TODO: Put this into a config file
    client::credentials cred("drose2011", "C++InDesign");
    client::http_client_config config{};
    config.set_credentials(cred);

    // TODO: Don't make this class twice
    client = client::http_client(base_uri, config);

    builder.append_query("extended", "1");
    for(std::string target : targets) {
        builder.append_query("icao24", target);
    }
}

void OpenSkyRESTClient::display_json(json::value const & jvalue)
{
    std::cout << jvalue.serialize() << std::endl;
}

std::vector<FlightStatusEvent> OpenSkyRESTClient::find_and_update_deltas(std::vector<FlightStatusEvent> all_events) {
    std::vector<FlightStatusEvent> updated_events{};
    for (FlightStatusEvent event : all_events) {
        std::string icao24 = event.getIcao24();
        bool no_change = (currentStates.count(icao24) && event == currentStates[icao24]);
        if (!no_change) {
            currentStates[icao24] = event;
            updated_events.push_back(event);
        }
    }
    return updated_events;
}

std::vector<FlightStatusEvent> OpenSkyRESTClient::make_request(client::http_client & client)
{
    std::vector<FlightStatusEvent> all_events{};

    client.request(methods::GET, builder.to_string())
        .then([this](const http_response& response)
        {
            json::value json_resp{json::value::null()};
            try {
                if (response.status_code() == status_codes::OK) {
                    json_resp = response.extract_json().get()["states"];
//                    display_json(json_resp);
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
                for (const auto &item: eventStates.as_array()) {
                    try {
                        auto dataArray = item.as_array();
                        FlightStatusEvent e(dataArray);
                        all_events.push_back(e);
                    } catch (http_exception& e) {
                        std::cout << e.error_code().message() << std::endl;
                    }
                }
            }
        })
        .wait();
    std::vector<FlightStatusEvent> updates = find_and_update_deltas(all_events);
    return updates;
}

// TODO: Add a map to keep track of which flights have been updated and which haven't
// TODO: Add a parameter for time?
std::vector<FlightStatusEvent> OpenSkyRESTClient::get_events() {
    return make_request(client);
}
