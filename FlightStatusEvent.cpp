//
// Created by Dylan Rose on 11/29/23.
//

#include "FlightStatusEvent.h"

FlightStatusEvent::FlightStatusEvent(const FlightStatusEvent &event) {
    m_icao24 = event.getIcao24();
    m_receiver_type = event.getReceiverType();
    m_callsign = event.getCallsign();
    m_registration = event.getRegistration();
    m_type = event.getType();
    m_baro_altitude = event.getBaroAltitude();
    m_geo_altitude = event.getGeoAltitude();
    m_nav_altitude = event.getNavAltitude();
    m_ground_speed = event.getGroundSpeed();
    m_indicated_airspeed = event.getIndicatedAirspeed();
    m_true_airspeed = event.getTrueAirspeed();
    m_outside_air_temp = event.getOutsideAirTemp();
    m_mag_track = event.getMagTrack();
    m_true_heading = event.getTrueHeading();
    m_squawk = event.getSquawk();
    m_emergency = event.getEmergency();
    m_category = event.getCategory();
    m_longitude = event.getLongitude();
    m_latitude = event.getLatitude();
}

FlightStatusEvent::FlightStatusEvent(web::json::value jvalue) {
    m_icao24 = (!jvalue["hex"].is_null()) ? jvalue["hex"].as_string() : "";
    m_receiver_type = (!jvalue["type"].is_null()) ? std::make_optional(jvalue["type"].as_string()) : std::nullopt;
    m_callsign = (!jvalue["flight"].is_null()) ? std::make_optional(jvalue["flight"].as_string()) : std::nullopt;
    m_registration = (!jvalue["r"].is_null()) ? std::make_optional(jvalue["r"].as_string()) : std::nullopt;
    m_type = (!jvalue["t"].is_null()) ? std::make_optional(jvalue["t"].as_string()) : std::nullopt;
    m_baro_altitude = (!jvalue["alt_baro"].is_null() && jvalue["alt_baro"].is_double()) ? std::make_optional(jvalue["alt_baro"].as_double())
                                                      : std::nullopt;
    m_geo_altitude = (!jvalue["alt_geom"].is_null()) ? std::make_optional(jvalue["alt_geom"].as_double())
                                                     : std::nullopt;
    m_nav_altitude = (!jvalue["nav_altitude_mcp"].is_null()) ? std::make_optional(
            jvalue["nav_altitude_mcp"].as_double()) : std::nullopt;
    m_ground_speed = (!jvalue["gs"].is_null()) ? std::make_optional(jvalue["gs"].as_double()) : std::nullopt;
    m_indicated_airspeed = (!jvalue["ias"].is_null()) ? std::make_optional(jvalue["ias"].as_double()) : std::nullopt;
    m_true_airspeed = (!jvalue["tas"].is_null()) ? std::make_optional(jvalue["tas"].as_double()) : std::nullopt;
    m_outside_air_temp = (!jvalue["oat"].is_null()) ? std::make_optional(jvalue["oat"].as_double()) : std::nullopt;
    m_mag_track = (!jvalue["mag_heading"].is_null()) ? std::make_optional(jvalue["mag_heading"].as_double())
                                                     : std::nullopt;
    m_true_heading = (!jvalue["true_heading"].is_null()) ? std::make_optional(jvalue["true_heading"].as_double())
                                                         : std::nullopt;
    m_squawk = (!jvalue["squawk"].is_null()) ? std::make_optional(jvalue["squawk"].as_string()) : std::nullopt;
    m_emergency = (!jvalue["emergency"].is_null()) ? std::make_optional(jvalue["emergency"].as_string()) : std::nullopt;
    m_category = (!jvalue["category"].is_null()) ? std::make_optional(jvalue["category"].as_string()) : std::nullopt;
    m_longitude = (!jvalue["lon"].is_null()) ? std::make_optional(jvalue["lon"].as_double()) : std::nullopt;
    m_latitude = (!jvalue["lat"].is_null()) ? std::make_optional(jvalue["lat"].as_double()) : std::nullopt;
}

FlightStatusEvent::FlightStatusEvent() {
}

const std::string &FlightStatusEvent::getIcao24() const {
    return m_icao24;
}

const std::optional<std::string> &FlightStatusEvent::getReceiverType() const {
    return m_receiver_type;
}

const std::optional<std::string> &FlightStatusEvent::getCallsign() const {
    return m_callsign;
}

const std::optional<std::string> &FlightStatusEvent::getRegistration() const {
    return m_registration;
}

const std::optional<std::string> &FlightStatusEvent::getType() const {
    return m_type;
}

const std::optional<float> &FlightStatusEvent::getBaroAltitude() const {
    return m_baro_altitude;
}

const std::optional<float> &FlightStatusEvent::getGeoAltitude() const {
    return m_geo_altitude;
}

const std::optional<float> &FlightStatusEvent::getNavAltitude() const {
    return m_nav_altitude;
}

const std::optional<float> &FlightStatusEvent::getGroundSpeed() const {
    return m_ground_speed;
}

const std::optional<float> &FlightStatusEvent::getIndicatedAirspeed() const {
    return m_indicated_airspeed;
}

const std::optional<float> &FlightStatusEvent::getTrueAirspeed() const {
    return m_true_airspeed;
}

const std::optional<float> &FlightStatusEvent::getOutsideAirTemp() const {
    return m_outside_air_temp;
}

const std::optional<float> &FlightStatusEvent::getMagTrack() const {
    return m_mag_track;
}

const std::optional<float> &FlightStatusEvent::getTrueHeading() const {
    return m_true_heading;
}

const std::optional<std::string> &FlightStatusEvent::getSquawk() const {
    return m_squawk;
}

const std::optional<std::string> &FlightStatusEvent::getEmergency() const {
    return m_emergency;
}

const std::optional<std::string> &FlightStatusEvent::getCategory() const {
    return m_category;
}

const std::optional<float> &FlightStatusEvent::getLongitude() const {
    return m_longitude;
}

const std::optional<float> &FlightStatusEvent::getLatitude() const {
    return m_latitude;
}
