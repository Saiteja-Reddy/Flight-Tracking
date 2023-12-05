//
// Created by Dylan Rose on 11/29/23.
//

#include "FlightStatusEvent.h"

FlightStatusEvent::FlightStatusEvent(const FlightStatusEvent &event) {
    m_icao24 = event.getIcao24();
    m_reciver_type = event.getReciverType();
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
    m_squak = event.getSquak();
    m_emergency = event.getEmergency();
    m_category = event.getCategory();
    m_longitude = event.getLongitude();
    m_latitude = event.getLatitude();
}

FlightStatusEvent::FlightStatusEvent(web::json::value jvalue) {
    m_icao24 = (!jvalue["hex"].is_null()) ? jvalue["hex"].as_string() : "";
    m_reciver_type = (!jvalue["type"].is_null()) ? std::make_optional(jvalue["type"].as_string()) : std::nullopt;
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
    m_squak = (!jvalue["squawk"].is_null()) ? std::make_optional(jvalue["squawk"].as_string()) : std::nullopt;
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
void FlightStatusEvent::setIcao24(const std::string &mIcao24) {
    m_icao24 = mIcao24;
}

const std::optional<std::string> &FlightStatusEvent::getReciverType() const {
    return m_reciver_type;
}
void FlightStatusEvent::setReciverType(const std::optional<std::string> &mReciverType) {
    m_reciver_type = mReciverType;
}

const std::optional<std::string> &FlightStatusEvent::getCallsign() const {
    return m_callsign;
}
void FlightStatusEvent::setCallsign(const std::optional<std::string> &mCallsign) {
    m_callsign = mCallsign;
}

const std::optional<std::string> &FlightStatusEvent::getRegistration() const {
    return m_registration;
}
void FlightStatusEvent::setRegistration(const std::optional<std::string> &mRegistration){
    m_registration = mRegistration;
}

const std::optional<std::string> &FlightStatusEvent::getType() const {
    return m_type;
}
void FlightStatusEvent::setType(const std::optional<std::string> &mType) {
    m_type = mType;
}

const std::optional<float> &FlightStatusEvent::getBaroAltitude() const {
    return m_baro_altitude;
}
void FlightStatusEvent::setBaroAltitude(const std::optional<float> &mBaroAltitude) {
    m_baro_altitude = mBaroAltitude;
}

const std::optional<float> &FlightStatusEvent::getGeoAltitude() const {
    return m_geo_altitude;
}
void FlightStatusEvent::setGeoAltitude(const std::optional<float> &mGeoAltitude) {
    m_geo_altitude = mGeoAltitude;
}

const std::optional<float> &FlightStatusEvent::getNavAltitude() const {
    return m_nav_altitude;
}
void FlightStatusEvent::setNavAltitude(const std::optional<float> &mNavAltitude) {
    m_nav_altitude = mNavAltitude;
}

const std::optional<float> &FlightStatusEvent::getGroundSpeed() const {
    return m_ground_speed;
}
void FlightStatusEvent::setGroundSpeed(const std::optional<float> &mGroundSpeed) {
    m_ground_speed = mGroundSpeed;
}

const std::optional<float> &FlightStatusEvent::getIndicatedAirspeed() const {
    return m_indicated_airspeed;
}
void FlightStatusEvent::setIndicatedAirspeed(const std::optional<float> &mIndicatedAirspeed) {
    m_indicated_airspeed = mIndicatedAirspeed;
}

const std::optional<float> &FlightStatusEvent::getTrueAirspeed() const {
    return m_true_airspeed;
}
void FlightStatusEvent::setTrueAirspeed(const std::optional<float> &mTrueAirspeed) {
    m_true_airspeed = mTrueAirspeed;
}

const std::optional<float> &FlightStatusEvent::getOutsideAirTemp() const {
    return m_outside_air_temp;
}
void FlightStatusEvent::setOutsideAirTemp(const std::optional<float> &mOutsideAirTemp){
    m_outside_air_temp = mOutsideAirTemp;
}

const std::optional<float> &FlightStatusEvent::getMagTrack() const {
    return m_mag_track;
}
void FlightStatusEvent::setMagTrack(const std::optional<float> &mMagTrack) {
    m_mag_track = mMagTrack;
}

const std::optional<float> &FlightStatusEvent::getTrueHeading() const {
    return m_true_heading;
}
void FlightStatusEvent::setTrueHeading(const std::optional<float> &mTrueHeading) {
    m_true_heading = mTrueHeading;
}

const std::optional<std::string> &FlightStatusEvent::getSquak() const {
    return m_squak;
}
void FlightStatusEvent::setSquak(const std::optional<std::string> &mSquak) {
    m_squak = mSquak;
}

const std::optional<std::string> &FlightStatusEvent::getEmergency() const {
    return m_emergency;
}
void FlightStatusEvent::setEmergency(const std::optional<std::string> &mEmergency) {
    m_emergency = mEmergency;
}

const std::optional<std::string> &FlightStatusEvent::getCategory() const {
    return m_category;
}
void FlightStatusEvent::setCategory(const std::optional<std::string> &mCategory) {
    m_category = mCategory;
}

const std::optional<float> &FlightStatusEvent::getLongitude() const {
    return m_longitude;
}
void FlightStatusEvent::setLongitude(const std::optional<float> &mLongitude) {
    m_longitude = mLongitude;
}

const std::optional<float> &FlightStatusEvent::getLatitude() const {
    return m_latitude;
}
void FlightStatusEvent::setLatitude(const std::optional<float> &mLatitude) {
    m_latitude = mLatitude;
}