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

    explicit FlightStatusEvent(web::json::array array);

    // Temporary to not break other code
    FlightStatusEvent();

    // copy constructor
    FlightStatusEvent(const FlightStatusEvent& event);

    friend std::ostream &operator<<(std::ostream &os, FlightStatusEvent const &event) {
        return os << "FlightStatusEvent{" << event.m_icao24 << "}";
    }

    friend bool operator==(FlightStatusEvent const &current, FlightStatusEvent const &other) {

        return current.m_icao24 == other.getIcao24() &&
               current.m_callsign == other.getCallsign() &&
               current.m_origin_country == other.getOriginCountry() &&
               current.m_time_position == other.getTimePosition() &&
               current.m_last_contact == other.getLastContact() &&
               current.m_longitude == other.getLongitude() &&
               current.m_latitude == other.getLatitude() &&
               current.m_baro_altitude == other.getBaroAltitude() &&
               current.m_on_ground == other.getOnGround() &&
               current.m_velocity == other.getVelocity() &&
               current.m_true_track == other.getTrueTrack() &&
               current.m_vertical_rate == other.getVerticalRate() &&
               // current.sensors == other.getSensors() &&
               current.m_geo_altitude == other.getGeoAltitude() &&
               current.m_squawk == other.getSquawk() &&
               current.m_spi == other.getSpi() &&
               current.m_position_source == other.getPositionSource() &&
               current.m_category == other.getCategory();
    }

    int getNum() const;

    void setNum(int num);

    std::string getIcao24() const;

    void setIcao24(const std::string &icao24);

    std::string getCallsign() const;

    void setCallsign(const std::string &callsign);

    std::string getOriginCountry() const;

    void setOriginCountry(const std::string &origin_country);

    int getTimePosition() const;

    void setTimePosition(int time_position);

    int getLastContact() const;

    void setLastContact(int last_contact);

    float getLongitude() const;

    void setLongitude(float longitude);

    float getLatitude() const;

    void setLatitude(float latitude);

    float getBaroAltitude() const;

    void setBaroAltitude(float baro_altitude);

    bool getOnGround() const;

    void setOnGround(bool on_ground);

    float getVelocity() const;

    void setVelocity(float velocity);

    float getTrueTrack() const;

    void setTrueTrack(float true_track);

    float getVerticalRate() const;

    void setVerticalRate(float vertical_rate);

    float getGeoAltitude() const;

    void setGeoAltitude(float geo_altitude);

    std::string getSquawk() const;

    void setSquawk(const std::string &squawk);

    bool getSpi() const;

    void setSpi(bool spi);

    int getPositionSource() const;

    void setPositionSource(int position_source);

    int getCategory() const;

    void setCategory(int category);

private:
    int m_num;
    std::string m_icao24;
    std::string m_callsign;
    std::string m_origin_country;
    int m_time_position{};
    int m_last_contact{};
    float m_longitude{};
    float m_latitude{};
    float m_baro_altitude{};
    bool m_on_ground{};
    float m_velocity{};
    float m_true_track{};
    float m_vertical_rate{};
//    web::json::array sensors;
    float m_geo_altitude{};
    std::string m_squawk;
    bool m_spi{};
    int m_position_source{};
    int m_category{};
};

#endif //FLIGHT_TRACK_FLIGHTSTATUSEVENT_H
