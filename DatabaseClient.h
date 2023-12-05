//
// Created by Sai Teja Reddy Moolamalla on 11/1/23.
//

#ifndef FLIGHT_TRACK_DATABASECLIENT_H
#define FLIGHT_TRACK_DATABASECLIENT_H

#include <iostream>
#include "SeparateThreadObserver.h"
#include "SQLiteCpp/Database.h"
#include "SQLiteCpp/VariadicBind.h"
#include "FlightStatusEvent.h"

/**
 * An Observer class which updates the database with flight statuses.
 */
class DatabaseClient : public SeparateThreadObserver<FlightStatusEvent> {
public:
    /**
     * Constructor
     */
    DatabaseClient() :
            db{SQLite::Database("example.db3",
                                SQLite::OPEN_READWRITE | SQLite::OPEN_CREATE)} {

        // Create a new table with an explicit "id" column aliasing the underlying rowid
        db.exec("DROP TABLE IF EXISTS test");
        db.exec("CREATE TABLE test (id INTEGER PRIMARY KEY, value TEXT)");
        db.exec(table_drop_table);
        db.exec(table_create_table);
    };

    /**
     * Function which processes the received flight status event.
     * Updates the backend database with the new flight status.
     * @param event received flight status
     */
    void processEvent(const FlightStatusEvent &event) override;

private:
    // Open a database file
    SQLite::Database db;

    std::string table_drop_table = "DROP TABLE IF EXISTS flights";

    std::string table_create_table = "create table flights("
                                     "icao24             TEXT PRIMARY KEY not null,\n"
                                     "callsign           TEXT,\n"
                                     "registration       TEXT,\n"
                                     "type               TEXT,\n"
                                     "baro_altitude      FLOAT,\n"
                                     "geo_altitude       FLOAT,\n"
                                     "nav_altitude       FLOAT,\n"
                                     "ground_speed       FLOAT,\n"
                                     "indicated_airspeed FLOAT,\n"
                                     "true_airspeed      FLOAT,\n"
                                     "outside_air_temp   FLOAT,\n"
                                     "mag_track          FLOAT,\n"
                                     "true_heading       FLOAT,\n"
                                     "longitude          FLOAT,\n"
                                     "latitude           FLOAT,\n"
                                     "squawk             TEXT,\n"
                                     "emergency          TEXT,\n"
                                     "category           TEXT\n"
                                     ")";

    /**
     * Returns SQL update string for flight status event
     * @param event input event
     * @return SQL update string
     */
    static std::string getSQLUpdateString(const FlightStatusEvent &event);
};

#endif //FLIGHT_TRACK_DATABASECLIENT_H
