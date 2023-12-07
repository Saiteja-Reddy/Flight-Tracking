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

/**
 * REST Client for ADSB.lol API.
 * ADSB.lol is a flight tracking network that aggregates data from volunteer feeders around the world.
 * The API docs are available here - https://api.adsb.lol/docs.
 * By default, all flights within 250nm of Columbia University are monitored.
 */
class ADSBlolRESTClient {
private:
    std::string base_uri;
    uri_builder builder;
    client::http_client client;
    /**
     * Keeps track of which specific flights are being monitored (empty = all)
     */
    std::vector<std::string> targets;
    /**
     * Keeps track of last datapoint for each aircraft
     */
    std::map<std::string, FlightStatusEvent> currentStates;

    /**
     * Updates currentStates vector with all new data points. Filters out all unchanged Events from return vector
     * @param all_events All events that are being updated
     * @return A subset of the all_events input that only includes events that have changed since the last update
     */
    std::vector<FlightStatusEvent> find_and_update_deltas(const std::vector<FlightStatusEvent> &all_events);

public:
    /**
     * Default constructor monitors all flights within 250nm of Columbia University
     */
    ADSBlolRESTClient();

    /**
     * Constructor which takes list of icao24 identifier strings and only returns updates on those flights
     * @param input_targets icao24 ids for all aircraft that should be monitored
     */
    ADSBlolRESTClient(std::vector<std::string>);

    /**
     * Displays a returned web::json::value
     * @param jvalue a web::json::value to be printed
     */
    static void display_json(json::value const &jvalue);

    /**
     * Sends a request for flight events using the given http_request object, error checks, and returns the result
     * @param request a web::http::http_request object with all required request parameters set (base, query, headers)
     * @return vector of FlightStatusEvents that was returned from the request
     */
    std::vector<FlightStatusEvent> make_request(const http_request &request);

    /**
     * Returns all FlightStatusEvent updates the class is set up to monitor
     * @return A vector of updated FlightStatusEvents
     */
    std::vector<FlightStatusEvent> get_events();
};


#endif //FLIGHT_TRACK_ADSBLOLRESTCLIENT_H
