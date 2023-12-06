//
// Created by Sai Teja Reddy Moolamalla on 11/1/23.
//

#include "DatabaseClient.h"


void DatabaseClient::processEvent(const FlightStatusEvent &event) {
    try {
        SQLite::Statement query(db, getSQLUpdateString(event));
        query.exec();
    }
    catch (std::exception &e) {
        std::cout << "exception: " << e.what() << std::endl;
        std::terminate();
    }
}

std::string DatabaseClient::getSQLUpdateString(const FlightStatusEvent &event) {
    std::string fields;
    std::string values;

    fields += "icao24";
    values += "'" + event.getIcao24() + "'";

    if (event.getCallsign().has_value()) {
        fields += ", callsign";
        values += ", '" + event.getCallsign().value() + "'";
    }

    if (event.getRegistration().has_value()) {
        fields += ", registration";
        values += ", '" + event.getRegistration().value() + "'";
    }

    if (event.getType().has_value()) {
        fields += ", type";
        values += ", '" + event.getType().value() + "'";
    }

    if (event.getBaroAltitude().has_value()) {
        fields += ", baro_altitude";
        values += ", " + std::to_string(event.getBaroAltitude().value());
    }

    if (event.getGeoAltitude().has_value()) {
        fields += ", geo_altitude";
        values += ", " + std::to_string(event.getGeoAltitude().value());
    }

    if (event.getNavAltitude().has_value()) {
        fields += ", nav_altitude";
        values += ", " + std::to_string(event.getNavAltitude().value());
    }

    if (event.getGroundSpeed().has_value()) {
        fields += ", ground_speed";
        values += ", " + std::to_string(event.getGroundSpeed().value());
    }

    if (event.getIndicatedAirspeed().has_value()) {
        fields += ", indicated_airspeed";
        values += ", " + std::to_string(event.getIndicatedAirspeed().value());
    }

    if (event.getTrueAirspeed().has_value()) {
        fields += ", true_airspeed";
        values += ", " + std::to_string(event.getTrueAirspeed().value());
    }

    if (event.getOutsideAirTemp().has_value()) {
        fields += ", outside_air_temp";
        values += ", " + std::to_string(event.getOutsideAirTemp().value());
    }

    if (event.getMagTrack().has_value()) {
        fields += ", mag_track";
        values += ", " + std::to_string(event.getMagTrack().value());
    }

    if (event.getTrueHeading().has_value()) {
        fields += ", true_heading";
        values += ", " + std::to_string(event.getTrueHeading().value());
    }

    if (event.getLongitude().has_value()) {
        fields += ", longitude";
        values += ", " + std::to_string(event.getLongitude().value());
    }

    if (event.getLatitude().has_value()) {
        fields += ", latitude";
        values += ", " + std::to_string(event.getLatitude().value());
    }

    if (event.getSquawk().has_value()) {
        fields += ", squawk";
        values += ", '" + event.getSquawk().value() + "'";
    }

    if (event.getEmergency().has_value()) {
        fields += ", emergency";
        values += ", '" + event.getEmergency().value() + "'";
    }

    if (event.getCategory().has_value()) {
        fields += ", category";
        values += ", '" + event.getCategory().value() + "'";
    }

    return "INSERT OR REPLACE INTO flights (" + fields + ") VALUES (" + values + ")";
}
