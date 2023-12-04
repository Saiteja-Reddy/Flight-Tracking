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
     * @return status error code
     */
    int processEvent(const FlightStatusEvent &event) override;

    void updateDB(int num);

private:
    // Open a database file
    SQLite::Database db;

    std::string table_drop_table = "DROP TABLE IF EXISTS flights";

    std::string table_create_table = "create table flights("
                                     "icao24          TEXT PRIMARY KEY not null,\n"
                                     "callsign        TEXT,\n"
                                     "origin_country  TEXT,\n"
                                     "longitude       FLOAT,\n"
                                     "last_contact    integer,\n"
                                     "latitude        float,\n"
                                     "baro_altitude   float,\n"
                                     "on_ground       INT,\n"
                                     "velocity        float,\n"
                                     "true_track      float,\n"
                                     "vertical_rate   float,\n"
                                     "geo_altitude    float,\n"
                                     "squawk          string,\n"
                                     "spi             integer,\n"
                                     "position_source integer,\n"
                                     "category        integer\n"
                                     ")";
};

#endif //FLIGHT_TRACK_DATABASECLIENT_H
