//
// Created by Dylan Rose on 11/29/23.
//

#ifndef FLIGHT_TRACK_OPENSKYRESTCLIENT_H
#define FLIGHT_TRACK_OPENSKYRESTCLIENT_H

#include <string>

#include <cpprest/http_client.h>

#include "FlightStatusEvent.h"

using namespace web;
using namespace web::http;

class OpenSkyRESTClient {
private:
    std::string base_uri;
    uri_builder builder;
    client::http_client client;
    std::vector<std::string> targets;
public:
    // TODO: A list of flights as input - new constructor
    // DONE: NULL check!
    // TODO: only send changes from the client
    // TODO: Add docs!
    // TODO: Getters and setters for FlightStatusEvents
    OpenSkyRESTClient();

    OpenSkyRESTClient(std::vector<std::string>);

    static void display_json(json::value const & jvalue);

    std::vector<FlightStatusEvent> make_request(client::http_client & client);

    std::vector<FlightStatusEvent> get_events();
};


#endif //FLIGHT_TRACK_OPENSKYRESTCLIENT_H
