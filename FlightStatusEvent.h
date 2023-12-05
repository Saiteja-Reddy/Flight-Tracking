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
        return current.m_icao24 == other.getIcao24() &&
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
               current.m_squawk == other.getSquawk() &&
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
    std::optional<std::string> m_squawk{};
    std::optional<std::string> m_emergency{};
    std::optional<std::string> m_category{};
    std::optional<float> m_longitude{};
    std::optional<float> m_latitude{};

public:

    /**
     * Fetch ICAO24 code.
     * Unique ICAO 24-bit address of the transponder in hex string representation.
     * @return the icao24 code
     */
    const std::string &getIcao24() const;

    /**
     * Fetch receiver type.
     * type of underlying messages / best source of current data for this position / aircraft: (the following list is in order of which data is preferentially used)
     * - adsb_icao: messages from a Mode S or ADS-B transponder, using a 24-bit ICAO address
     * - adsb_icao_nt: messages from an ADS-B equipped "non-transponder" emitter e.g. a ground vehicle, using a 24-bit ICAO address
     * - adsr_icao: rebroadcast of ADS-B messages originally sent via another data link e.g. UAT, using a 24-bit ICAO address
     * - tisb_icao: traffic information about a non-ADS-B target identified by a 24-bit ICAO address, e.g. a Mode S target tracked by secondary radar
     * - adsc: ADS-C (received by monitoring satellite downlinks)
     * - mlat: MLAT, position calculated arrival time differences using multiple receivers, outliers and varying accuracy is expected.
     * - other: miscellaneous data received via Basestation / SBS format, quality / source is unknown.
     * - mode_s: ModeS data from the planes transponder (no position transmitted)
     * - adsb_other: messages from an ADS-B transponder using a non-ICAO address, e.g. anonymized address
     * - adsr_other: rebroadcast of ADS-B messages originally sent via another data link e.g. UAT, using a non-ICAO address
     * - tisb_other: traffic information about a non-ADS-B target using a non-ICAO address
     * - tisb_trackfile: traffic information about a non-ADS-B target using a track/file identifier, typically from primary or Mode A/C radar
     * @return the receiver type
     */
    const std::optional<std::string> &getReceiverType() const;

    /**
     * Fetch call sign.
     * The flight name or aircraft registration as 8 chars (2.2.8.2.6)
     * @return the call sign
     */
    const std::optional<std::string> &getCallsign() const;

    /**
     * Fetch the aircraft registration pulled from database
     * @return the aircraft registration
     */
    const std::optional<std::string> &getRegistration() const;

    /**
     * Fetch the aircraft type pulled from database
     * @return the aircraft type
     */
    const std::optional<std::string> &getType() const;

    /**
     * Fetch the barometer altitude
     * the aircraft barometric altitude in feet as a number OR "ground" as a string
     * @return the barometer altitude
     */
    const std::optional<float> &getBaroAltitude() const;

    /**
     * Fetch the geometric altitude
     * the geometric (GNSS / INS) altitude in feet referenced to the WGS84 ellipsoid
     * @return the geometric altitude
     */
    const std::optional<float> &getGeoAltitude() const;

    /**
     * Fetch the nav altitude
     * selected altitude from the Mode Control Panel / Flight Control Unit (MCP/FCU) or equivalent equipment
     * @return the nav altitude
     */
    const std::optional<float> &getNavAltitude() const;

    /**
     * Fetch the ground speed in knots
     * @return the ground speed
     */
    const std::optional<float> &getGroundSpeed() const;

    /**
     * Fetch the indicated air speed in knots
     * @return the indicated air speed
     */
    const std::optional<float> &getIndicatedAirspeed() const;

    /**
     * Fetch the true air speed in knots
     * @return the true air speed
     */
    const std::optional<float> &getTrueAirspeed() const;

    /**
     * Fetch the outer air temperature
     * calculated from mach number and true airspeed (typically somewhat inaccurate at lower
     * altitudes / mach numbers below 0.5, calculation is inhibited for mach < 0.395)
     * @return the outer air temperature
     */
    const std::optional<float> &getOutsideAirTemp() const;

    /**
     * Fetch the magnetic heading
     * Heading, degrees clockwise from magnetic north
     * @return the magnetic heading
     */
    const std::optional<float> &getMagTrack() const;

    /**
     * Fetch the true heading
     * Heading, degrees clockwise from true north (usually only transmitted on ground,
     * in the air usually derived from the magnetic heading using magnetic model WMM2020)
     * @return the true heading
     */
    const std::optional<float> &getTrueHeading() const;

    /**
     * Fetch the transponder Squawk code
     * Mode A code (Squawk), encoded as 4 octal digits
     * @return the transponder Squawk code
     */
    const std::optional<std::string> &getSquawk() const;

    /**
     * Fetch the emergency/priority status
     * ADS-B emergency/priority status, a superset of the 7x00 squawks (2.2.3.2.7.8.1.1)
     * (none, general, lifeguard, minfuel, nordo, unlawful, downed, reserved)
     * @return the emergency/priority status
     */
    const std::optional<std::string> &getEmergency() const;

    /**
     * Fetch the emitter category
     * emitter category to identify particular aircraft or vehicle classes
     * (values A0 - D7) (2.2.3.2.5.2)
     * @return the emitter category
     */
    const std::optional<std::string> &getCategory() const;

    /**
     * Fetch longitude
     * WGS-84 longitude in decimal degrees. Can be null.
     * @return the longitude
     */
    const std::optional<float> &getLongitude() const;

    /**
     * Fetch latitude
     * WGS-84 latitude in decimal degrees. Can be null.
     * @return the latitude
     */
    const std::optional<float> &getLatitude() const;
};

#endif //FLIGHT_TRACK_FLIGHTSTATUSEVENT_H