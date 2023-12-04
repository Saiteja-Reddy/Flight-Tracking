//
// Created by Sai Teja Reddy Moolamalla on 11/1/23.
//

#include "DatabaseClient.h"


void DatabaseClient::processEvent(const FlightStatusEvent& event) {
    std::cout << "Received database event " << event << std::endl;
}

void DatabaseClient::updateDB(int num) {
    try
    {
        SQLite::Statement query(db, "INSERT INTO test VALUES (NULL, ?)");
        SQLite::bind(query, num);
        int nb = query.exec();
        std::cout << "INSERT INTO test VALUES (NULL, " << num << ")\", returned " << nb << '\n';
    }
    catch (std::exception& e)
    {
        std::cout << "exception: " << e.what() << std::endl;
    }
}
