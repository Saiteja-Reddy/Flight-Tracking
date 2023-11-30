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
public:
    OpenSkyRESTClient();

    static void display_json(json::value const & jvalue);
    std::vector<FlightStatusEvent> make_request(client::http_client & client);

    std::vector<FlightStatusEvent> get_events();
};


#endif //FLIGHT_TRACK_OPENSKYRESTCLIENT_H
