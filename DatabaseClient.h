//
// Created by Sai Teja Reddy Moolamalla on 11/1/23.
//

#ifndef FLIGHT_TRACK_DATABASECLIENT_H
#define FLIGHT_TRACK_DATABASECLIENT_H

#include <iostream>
#include "SeparateThreadObserver.h"
#include "SQLiteCpp/Database.h"
#include "SQLiteCpp/VariadicBind.h"

class DatabaseClient : public SeparateThreadObserver {
public:
    DatabaseClient() :
            db{SQLite::Database("example.db3",
                                SQLite::OPEN_READWRITE | SQLite::OPEN_CREATE)} {

        // Create a new table with an explicit "id" column aliasing the underlying rowid
        db.exec("DROP TABLE IF EXISTS test");
        db.exec("CREATE TABLE test (id INTEGER PRIMARY KEY, value TEXT)");
    };

    int processEvent(int i) override;

    void updateDB(int num);

private:
    // Open a database file
    SQLite::Database db;

};


#endif //FLIGHT_TRACK_DATABASECLIENT_H
