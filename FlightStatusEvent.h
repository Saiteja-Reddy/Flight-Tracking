//
// Created by Sai Teja Reddy Moolamalla on 11/28/23.
//

#ifndef FLIGHT_TRACK_FLIGHTSTATUSEVENT_H
#define FLIGHT_TRACK_FLIGHTSTATUSEVENT_H

#include <string>
#include <cpprest/http_client.h>

/**
 * Class to encapsulate a flight state.
 */
class FlightStatusEvent {
public:
    std::string icao24;
    std::string callsign;
    std::string origin_country;
    int time_position;
    int last_contact;
    float longitude;
    float latitude;
    float baro_altitude;
    bool on_gound;
    float velocity;
    float true_track;
    float vertical_rate;
//    web::json::array sensors;
    float geo_altitude;
    std::string squawk;
    bool spi;
    int position_source;
    int category;

    FlightStatusEvent(web::json::array array);

    // Temporary to not break other code
    FlightStatusEvent();
    int getNum() const;
};

#endif //FLIGHT_TRACK_FLIGHTSTATUSEVENT_H
