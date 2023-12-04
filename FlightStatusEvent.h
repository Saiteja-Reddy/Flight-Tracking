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

    /**
     * Constructor
     * @param array array output from REST call
     */
    explicit FlightStatusEvent(web::json::array array);

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

    /**
     * Fetch ICAO24 code.
     * Unique ICAO 24-bit address of the transponder in hex string representation.
     * @return the icao24 code
     */
    std::string getIcao24() const;

    /**
     * Setter for ICAO24 code
     * @param icao24 input code
     */
    void setIcao24(const std::string &icao24);

    /**
     * Fetch call sign.
     * Callsign of the vehicle (8 chars). Can be null if no callsign has been received.
     * @return the call sign
     */
    std::string getCallsign() const;


    /**
     * Setter for call sign
     * @param callsign call sign
     */
    void setCallsign(const std::string &callsign);

    /**
     * Fetch origin country
     * Country name inferred from the ICAO 24-bit address.
     * @return the origin country
     */
    std::string getOriginCountry() const;

    /**
     * Setter for origin country
     * @param origin_country origin country
     */
    void setOriginCountry(const std::string &origin_country);

    /**
     * Fetch time position.
     * Unix timestamp (seconds) for the last position update. Can be null if no position report was received by OpenSky within the past 15s.
     * @return the time position
     */
    int getTimePosition() const;

    /**
     * Setter for time position
     * @param time_position time position
     */
    void setTimePosition(int time_position);

    /**
     * Fetch last contact
     * Unix timestamp (seconds) for the last update in general. This field is updated for any new, valid message received from the transponder.
     * @return the last contact
     */
    int getLastContact() const;

    /**
     * Setter for last contact
     * @param last_contact last contact
     */
    void setLastContact(int last_contact);

    /**
     * Fetch longitude
     * WGS-84 longitude in decimal degrees. Can be null.
     * @return the longitude
     */
    float getLongitude() const;

    /**
     * Setter for longitude
     * @param longitude longitude
     */
    void setLongitude(float longitude);

    /**
     * Fetch latitude
     * WGS-84 latitude in decimal degrees. Can be null.
     * @return the latitude
     */
    float getLatitude() const;

    /**
     * Setter for latitude
     * @param latitude latitude
     */
    void setLatitude(float latitude);

    /**
     * Fetch Barometric altitude.
     * Barometric altitude in meters. Can be null.
     * @return the Barometric altitude
     */
    float getBaroAltitude() const;

    /**
     * Setter for Barometric altitude
     * @param baro_altitude Barometric altitude
     */
    void setBaroAltitude(float baro_altitude);

    /**
     * Fetch on ground status.
     * Boolean value which indicates if the position was retrieved from a surface position report.
     * @return the on ground status
     */
    bool getOnGround() const;

    /**
     * Setter for ground status
     * @param on_ground ground status
     */
    void setOnGround(bool on_ground);

    /**
     * Fetch velocity over ground in m/s. Can be null.
     * @return the velocity
     */
    float getVelocity() const;

    /**
     * Setter for velocity
     * @param velocity velocity
     */
    void setVelocity(float velocity);

    /**
     * Fetch true track
     * True track in decimal degrees clockwise from north (north=0°). Can be null.
     * @return true track
     */
    float getTrueTrack() const;

    /**
     * Setter for true track
     * @param true_track true track
     */
    void setTrueTrack(float true_track);

    /**
     * Fetch vertical rate
     * Vertical rate in m/s. A positive value indicates that the airplane is climbing, a negative value indicates that it descends. Can be null.
     * @return the vertical rate
     */
    float getVerticalRate() const;

    /**
     * Setter for vertical rate
     * @param vertical_rate vertical rate
     */
    void setVerticalRate(float vertical_rate);

    /**
     * Fetch geometric altitude.
     * Geometric altitude in meters. Can be null.
     * @return the geometric altitude
     */
    float getGeoAltitude() const;

    /**
     * Setter for geometric altitude
     * @param geo_altitude geometric altitude
     */
    void setGeoAltitude(float geo_altitude);

    /**
     * Fetch the transponder code aka Squawk. Can be null.
     * @return the transponder code
     */
    std::string getSquawk() const;

    /**
     * Setter for transponder code aka Squawk
     * @param squawk squawk code
     */
    void setSquawk(const std::string &squawk);

    /**
     * Fetch SPI
     * Whether flight status indicates special purpose indicator.
     * @return the SPI
     */
    bool getSpi() const;

    /**
     * Setter for SPI
     * @param spi SPI
     */
    void setSpi(bool spi);

    /**
     * Fetch the position source
     * The origin of this state’s position.
     * 0 = ADS-B
     * 1 = ASTERI
     * 2 = MLAT
     * 3 = FLARM
     * @return the position source
     */
    int getPositionSource() const;

    /**
     * Setter for position source
     * @param position_source position source
     */
    void setPositionSource(int position_source);

    /**
     * Fetch the aircraft category
     * 0 = No information at all
     * 1 = No ADS-B Emitter Category Information
     * 2 = Light (< 15500 lbs)
     * 3 = Small (15500 to 75000 lbs)
     * 4 = Large (75000 to 300000 lbs)
     * 5 = High Vortex Large (aircraft such as B-757)
     * 6 = Heavy (> 300000 lbs)
     * 7 = High Performance (> 5g acceleration and 400 kts)
     * 8 = Rotorcraft
     * 9 = Glider / sailplane
     * 10 = Lighter-than-air
     * 11 = Parachutist / Skydiver
     * 12 = Ultralight / hang-glider / paraglider
     * 13 = Reserved
     * 14 = Unmanned Aerial Vehicle
     * 15 = Space / Trans-atmospheric vehicle
     * 16 = Surface Vehicle – Emergency Vehicle
     * 17 = Surface Vehicle – Service Vehicle
     * 18 = Point Obstacle (includes tethered balloons)
     * 19 = Cluster Obstacle
     * 20 = Line Obstacle
     * @return the the aircraft category
     */
    int getCategory() const;

    /**
     * Setter for aircraft category
     * @param category the aircraft category
     */
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
