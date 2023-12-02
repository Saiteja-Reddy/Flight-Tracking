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

    bool operator==(FlightStatusEvent const& other) {
        return icao24 == other.getIcao24() &&
                callsign == other.getCallsign() &&
                origin_country == other.getOriginCountry() &&
                time_position == other.getTimePosition() &&
                last_contact == other.getLastContact() &&
                longitude == other.getLongitude() &&
                latitude == other.getLatitude() &&
                baro_altitude == other.getBaroAltitude() &&
                on_gound == other.getOnGound() &&
                velocity == other.getVelocity() &&
                true_track == other.getTrueTrack() &&
                vertical_rate == other.getVerticalRate() &&
//                sensors == other.getSensors() &&
                geo_altitude == other.getGeoAltitude() &&
                squawk == other.getSquawk() &&
                spi == other.getSpi() &&
                position_source == other.getPositionSource() &&
                category == other.getCategory();
    }

    int getNum() const;

    std::string getIcao24() const;

private:
    std::string icao24;
public:
    const std::string &getCallsign() const;

    const std::string &getOriginCountry() const;

    int getTimePosition() const;

    int getLastContact() const;

    float getLongitude() const;

    float getLatitude() const;

    float getBaroAltitude() const;

    bool getOnGound() const;

    float getVelocity() const;

    float getTrueTrack() const;

    float getVerticalRate() const;

    float getGeoAltitude() const;

    const std::string &getSquawk() const;

    bool getSpi() const;

    int getPositionSource() const;

    int getCategory() const;

private:
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
