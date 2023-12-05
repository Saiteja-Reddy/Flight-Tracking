//
// Created by Dylan Rose on 11/29/23.
//

#ifndef FLIGHT_TRACK_ADSBLOLRESTCLIENT_H
#define FLIGHT_TRACK_ADSBLOLRESTCLIENT_H

#include <string>

#include <cpprest/http_client.h>

#include "FlightStatusEvent.h"

using namespace web;
using namespace web::http;

class ADSBlolRESTClient {
private:
    std::string base_uri;
    uri_builder builder;
    client::http_client client;
    std::vector<std::string> targets;
    std::map<std::string, FlightStatusEvent> currentStates;

    std::vector<FlightStatusEvent> find_and_update_deltas(std::vector<FlightStatusEvent> all_events);

public:
    // TODO: A list of flights as input - new constructor
    // TODO: only send changes from the client
    // TODO: Add docs!
    // TODO: Use enums/type checks for flight status event params
    // TODO: API is down? What to demo?? Have an alternative API?
    // DONE: Getters and setters for FlightStatusEvents
    ADSBlolRESTClient();

    ADSBlolRESTClient(std::vector<std::string>);

    static void display_json(json::value const &jvalue);

    std::vector<FlightStatusEvent> make_request(http_request request);

    std::vector<FlightStatusEvent> get_events();
};


#endif //FLIGHT_TRACK_ADSBLOLRESTCLIENT_H
