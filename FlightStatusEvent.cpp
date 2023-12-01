//
// Created by Dylan Rose on 11/29/23.
//

#include "FlightStatusEvent.h"

FlightStatusEvent::FlightStatusEvent(web::json::array array) {
    icao24 = (!array[0].is_null()) ? array[0].as_string() : "";
    callsign = (!array[1].is_null()) ? array[1].as_string() : "";
    origin_country = (!array[2].is_null()) ? array[2].as_string() : "";
    time_position = (!array[3].is_null()) ? array[3].as_integer() : 0;
    last_contact = (!array[4].is_null()) ? array[4].as_integer() : 0;
    longitude = (!array[5].is_null()) ? array[5].as_double() : 0;
    latitude = (!array[6].is_null()) ? array[6].as_double() : 0;
    baro_altitude = (!array[7].is_null()) ? array[7].as_double() : 0;
    on_gound = (!array[8].is_null()) ? array[8].as_bool() : false;
    velocity = (!array[9].is_null()) ? array[9].as_integer() : 0;
    true_track = (!array[10].is_null()) ? array[10].as_integer() : 0;
    vertical_rate = (!array[11].is_null()) ? array[11].as_integer() : 0;
//    sensors = (!array[12].is_null()) ? array[12].as_array() : web::json::array();
    geo_altitude = (!array[13].is_null()) ? array[13].as_double() : 0;
    squawk = (!array[14].is_null()) ? array[14].as_string() : "";
    spi = (!array[15].is_null()) ? array[15].as_bool() : false;
    position_source = (!array[16].is_null()) ? array[16].as_integer() : 0;
    category = (!array[17].is_null()) ? array[17].as_integer() : 0;
}

// Temporary to not break other code
FlightStatusEvent::FlightStatusEvent() {}
int FlightStatusEvent::getNum() const {
    return rand() % 1000;
}

std::string FlightStatusEvent::getIcao24() const {
    return icao24;
}