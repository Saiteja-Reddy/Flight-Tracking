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

    FlightStatusEvent(web::json::array array);

    // Temporary to not break other code
    FlightStatusEvent();

    friend std::ostream& operator<<(std::ostream& os, FlightStatusEvent const & event) {
        return os << "FlightStatusEvent{" << event.icao24  << "}";
    }

    int getNum() const;

    std::string getIcao24() const;

private:
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

};

#endif //FLIGHT_TRACK_FLIGHTSTATUSEVENT_H
