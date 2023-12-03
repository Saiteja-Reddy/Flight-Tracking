//
// Created by Dylan Rose on 11/29/23.
//

#include "FlightStatusEvent.h"

FlightStatusEvent::FlightStatusEvent(web::json::array array) {
    m_num = rand() % 1000;
    m_icao24 = (!array[0].is_null()) ? array[0].as_string() : "";
    m_callsign = (!array[1].is_null()) ? array[1].as_string() : "";
    m_origin_country = (!array[2].is_null()) ? array[2].as_string() : "";
    m_time_position = (!array[3].is_null()) ? array[3].as_integer() : 0;
    m_last_contact = (!array[4].is_null()) ? array[4].as_integer() : 0;
    m_longitude = (!array[5].is_null()) ? array[5].as_double() : 0;
    m_latitude = (!array[6].is_null()) ? array[6].as_double() : 0;
    m_baro_altitude = (!array[7].is_null()) ? array[7].as_double() : 0;
    m_on_ground = (!array[8].is_null()) && array[8].as_bool();
    m_velocity = (!array[9].is_null()) ? array[9].as_integer() : 0;
    m_true_track = (!array[10].is_null()) ? array[10].as_integer() : 0;
    m_vertical_rate = (!array[11].is_null()) ? array[11].as_integer() : 0;
//    sensors = (!array[12].is_null()) ? array[12].as_array() : web::json::array();
    m_geo_altitude = (!array[13].is_null()) ? array[13].as_double() : 0;
    m_squawk = (!array[14].is_null()) ? array[14].as_string() : "";
    m_spi = (!array[15].is_null()) && array[15].as_bool();
    m_position_source = (!array[16].is_null()) ? array[16].as_integer() : 0;
    m_category = (!array[17].is_null()) ? array[17].as_integer() : 0;
}

FlightStatusEvent::FlightStatusEvent(const FlightStatusEvent &event) {
    m_num = event.getNum();
    m_icao24 = event.getIcao24();
    m_callsign = event.getCallsign();
    m_origin_country = event.getOriginCountry();
    m_time_position = event.getTimePosition();
    m_last_contact = event.getLastContact();
    m_longitude = event.getLongitude();
    m_latitude = event.getLatitude();
    m_baro_altitude = event.getBaroAltitude();
    m_on_ground = event.getOnGround();
    m_velocity = event.getVelocity();
    m_true_track = event.getTrueTrack();
    m_vertical_rate = event.getVerticalRate();
    m_geo_altitude = event.getGeoAltitude();
    m_squawk = event.getSquawk();
    m_spi = event.getSpi();
    m_position_source = event.getPositionSource();
    m_category = event.getCategory();
}

// TODO: Remove this and add stop command?
// Temporary to not break other code
FlightStatusEvent::FlightStatusEvent() {
    m_num = rand() % 1000;
}

int FlightStatusEvent::getNum() const {
    return m_num;
}

void FlightStatusEvent::setNum(int num) { m_num = num; }

std::string FlightStatusEvent::getIcao24() const {
    return m_icao24;
}

void FlightStatusEvent::setIcao24(const std::string &icao24) { m_icao24 = icao24; }

std::string FlightStatusEvent::getCallsign() const {
    return m_callsign;
}

void FlightStatusEvent::setCallsign(const std::string &callsign) { m_callsign = callsign; }

std::string FlightStatusEvent::getOriginCountry() const {
    return m_origin_country;
}

void FlightStatusEvent::setOriginCountry(const std::string &origin_country) { m_origin_country = origin_country; }

int FlightStatusEvent::getTimePosition() const {
    return m_time_position;
}

void FlightStatusEvent::setTimePosition(int time_position) { m_time_position = time_position; }


int FlightStatusEvent::getLastContact() const {
    return m_last_contact;
}

void FlightStatusEvent::setLastContact(int last_contact) { m_last_contact = last_contact; }

float FlightStatusEvent::getLongitude() const {
    return m_longitude;
}

void FlightStatusEvent::setLongitude(float longitude) { m_longitude = longitude; }

float FlightStatusEvent::getLatitude() const {
    return m_latitude;
}

void FlightStatusEvent::setLatitude(float latitude) { m_latitude = latitude; }

float FlightStatusEvent::getBaroAltitude() const {
    return m_baro_altitude;
}

void FlightStatusEvent::setBaroAltitude(float baro_altitude) { m_baro_altitude = baro_altitude; }


bool FlightStatusEvent::getOnGround() const {
    return m_on_ground;
}

void FlightStatusEvent::setOnGround(bool on_ground) {
    m_on_ground = on_ground;
}

float FlightStatusEvent::getVelocity() const {
    return m_velocity;
}

void FlightStatusEvent::setVelocity(float velocity) { m_velocity = velocity; }


float FlightStatusEvent::getTrueTrack() const {
    return m_true_track;
}

void FlightStatusEvent::setTrueTrack(float true_track) { m_true_track = true_track; }

float FlightStatusEvent::getVerticalRate() const {
    return m_vertical_rate;
}

void FlightStatusEvent::setVerticalRate(float vertical_rate) { m_vertical_rate = vertical_rate; }


float FlightStatusEvent::getGeoAltitude() const {
    return m_geo_altitude;
}

void FlightStatusEvent::setGeoAltitude(float geo_altitude) { m_geo_altitude = geo_altitude; }


std::string FlightStatusEvent::getSquawk() const {
    return m_squawk;
}

void FlightStatusEvent::setSquawk(const std::string &squawk) { m_squawk = squawk; }

bool FlightStatusEvent::getSpi() const {
    return m_spi;
}

void FlightStatusEvent::setSpi(bool spi) {
    m_spi = spi;
}

int FlightStatusEvent::getPositionSource() const {
    return m_position_source;
}

void FlightStatusEvent::setPositionSource(int position_source) {
    m_position_source = position_source;
}

int FlightStatusEvent::getCategory() const {
    return m_category;
}

void FlightStatusEvent::setCategory(int category) {
    m_category = category;
}