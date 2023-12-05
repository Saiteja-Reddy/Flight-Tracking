//
// Created by Sai Teja Reddy Moolamalla on 11/1/23.
//

#include "DatabaseClient.h"


void DatabaseClient::processEvent(const FlightStatusEvent &event) {
    std::cout << "Received database event " << event << std::endl;
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

    fields += "icao24, ";
    values += "'" + event.getIcao24() + "', ";

//    if (event.getCallsign().has_value()) {
//        fields += "callsign, ";
//        values += "'" + event.getCallsign().value() + "', ";
//    }
//
//    fields += "origin_country, ";
//    values += "'" + event.getOriginCountry() + "', ";
//
//    if (event.getTimePosition().has_value()) {
//        fields += "time_position, ";
//        values += std::to_string(event.getTimePosition().value()) + ", ";
//    }
//
//    fields += "last_contact, ";
//    values += std::to_string(event.getLastContact()) + ", ";
//
//    if (event.getLongitude().has_value()) {
//        fields += "longitude, ";
//        values += std::to_string(event.getLongitude().value()) + ", ";
//    }
//
//    if (event.getLatitude().has_value()) {
//        fields += "latitude, ";
//        values += std::to_string(event.getLatitude().value()) + ", ";
//    }
//
//    if (event.getBaroAltitude().has_value()) {
//        fields += "baro_altitude, ";
//        values += std::to_string(event.getBaroAltitude().value()) + ", ";
//    }
//
//    fields += "on_ground, ";
//    values += std::to_string(event.getOnGround()) + ", ";
//
//    if (event.getVelocity().has_value()) {
//        fields += "velocity, ";
//        values += std::to_string(event.getVelocity().value()) + ", ";
//    }
//
//    if (event.getTrueTrack().has_value()) {
//        fields += "true_track, ";
//        values += std::to_string(event.getTrueTrack().value()) + ", ";
//    }
//
//    if (event.getVerticalRate().has_value()) {
//        fields += "vertical_rate, ";
//        values += std::to_string(event.getVerticalRate().value()) + ", ";
//    }
//
//    if (event.getGeoAltitude().has_value()) {
//        fields += "geo_altitude, ";
//        values += std::to_string(event.getGeoAltitude().value()) + ", ";
//    }
//
//    if (event.getSquawk().has_value()) {
//        fields += "squawk, ";
//        values += "'" + event.getSquawk().value() + "', ";
//    }
//
//    fields += "spi, ";
//    values += std::to_string(event.getSpi()) + ", ";
//
//    fields += "position_source, ";
//    values += std::to_string(event.getPositionSource()) + ", ";
//
//    fields += "category";
//    values += std::to_string(event.getCategory());

    return "INSERT OR REPLACE INTO flights (" + fields + ") VALUES (" + values + ")";
}
