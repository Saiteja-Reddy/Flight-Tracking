//
// Created by Sai Teja Reddy Moolamalla on 11/28/23.
//

#ifndef FLIGHT_TRACK_FLIGHTSTATUSEVENT_H
#define FLIGHT_TRACK_FLIGHTSTATUSEVENT_H

#include <string>
#include <cpprest/http_client.h>
#include <optional>

/**
 * Class to encapsulate a flight state.
 */
class FlightStatusEvent {

public:

    /**
     * Constructor
     * @param array array output from REST call
     */
    explicit FlightStatusEvent(web::json::value jvalue);

    /**
     * Default constructor
     */
    FlightStatusEvent();

    /**
     * Copy constructor
     * @param event
     */
    FlightStatusEvent(const FlightStatusEvent &event);

    friend std::ostream &operator<<(std::ostream &os, FlightStatusEvent const &event) {
        return os << "FlightStatusEvent{" << event.m_icao24 << "}";
    }

    friend bool operator==(FlightStatusEvent const &current, FlightStatusEvent const &other) {
        return  current.m_icao24 == other.getIcao24() &&
                current.m_receiver_type == other.getReceiverType() &&
                current.m_callsign == other.getCallsign() &&
                current.m_registration == other.getRegistration() &&
                current.m_type == other.getType() &&
                current.m_baro_altitude == other.getBaroAltitude() &&
                current.m_geo_altitude == other.getGeoAltitude() &&
                current.m_nav_altitude == other.getNavAltitude() &&
                current.m_ground_speed == other.getGroundSpeed() &&
                current.m_indicated_airspeed == other.getIndicatedAirspeed() &&
                current.m_true_airspeed == other.getTrueAirspeed() &&
                current.m_outside_air_temp == other.getOutsideAirTemp() &&
                current.m_mag_track == other.getMagTrack() &&
                current.m_true_heading == other.getTrueHeading() &&
                current.m_squak == other.getSquak() &&
                current.m_emergency == other.getEmergency() &&
                current.m_category == other.getCategory() &&
                current.m_longitude == other.getLongitude() &&
                current.m_latitude == other.getLatitude();
    }

private:
    std::string m_icao24;
    std::optional<std::string> m_receiver_type;
    std::optional<std::string> m_callsign;
    std::optional<std::string> m_registration;
    std::optional<std::string> m_type;
    std::optional<float> m_baro_altitude{};
    std::optional<float> m_geo_altitude{};
    std::optional<float> m_nav_altitude{};
    std::optional<float> m_ground_speed{};
    std::optional<float> m_indicated_airspeed{};
    std::optional<float> m_true_airspeed{};
    std::optional<float> m_outside_air_temp{};
    std::optional<float> m_mag_track{};
    std::optional<float> m_true_heading{};
    std::optional<std::string> m_squak{};
    std::optional<std::string> m_emergency{};
    std::optional<std::string> m_category{};
    std::optional<float> m_longitude{};
    std::optional<float> m_latitude{};

public:
    const std::string &getIcao24() const;
    void setIcao24(const std::string &mIcao24);

    const std::optional<std::string> &getReceiverType() const;
    void setReceiverType(const std::optional<std::string> &mReceiverType);

    const std::optional<std::string> &getCallsign() const;
    void setCallsign(const std::optional<std::string> &mCallsign);

    const std::optional<std::string> &getRegistration() const;
    void setRegistration(const std::optional<std::string> &mRegistration);

    const std::optional<std::string> &getType() const;
    void setType(const std::optional<std::string> &mType);

    const std::optional<float> &getBaroAltitude() const;
    void setBaroAltitude(const std::optional<float> &mBaroAltitude);

    const std::optional<float> &getGeoAltitude() const;
    void setGeoAltitude(const std::optional<float> &mGeoAltitude);

    const std::optional<float> &getNavAltitude() const;
    void setNavAltitude(const std::optional<float> &mNavAltitude);

    const std::optional<float> &getGroundSpeed() const;
    void setGroundSpeed(const std::optional<float> &mGroundSpeed);

    const std::optional<float> &getIndicatedAirspeed() const;
    void setIndicatedAirspeed(const std::optional<float> &mIndicatedAirspeed);

    const std::optional<float> &getTrueAirspeed() const;
    void setTrueAirspeed(const std::optional<float> &mTrueAirspeed);

    const std::optional<float> &getOutsideAirTemp() const;
    void setOutsideAirTemp(const std::optional<float> &mOutsideAirTemp);

    const std::optional<float> &getMagTrack() const;
    void setMagTrack(const std::optional<float> &mMagTrack);

    const std::optional<float> &getTrueHeading() const;
    void setTrueHeading(const std::optional<float> &mTrueHeadinge);

    const std::optional<std::string> &getSquak() const;
    void setSquak(const std::optional<std::string> &mSquak);

    const std::optional<std::string> &getEmergency() const;
    void setEmergency(const std::optional<std::string> &mEmergency);

    const std::optional<std::string> &getCategory() const;
    void setCategory(const std::optional<std::string> &mCategory);

    const std::optional<float> &getLongitude() const;
    void setLongitude(const std::optional<float> &mLongitude);

    const std::optional<float> &getLatitude() const;
    void setLatitude(const std::optional<float> &mLatitude);
};

#endif //FLIGHT_TRACK_FLIGHTSTATUSEVENT_H