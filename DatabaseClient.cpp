//
// Created by Sai Teja Reddy Moolamalla on 11/1/23.
//

#include "DatabaseClient.h"


int DatabaseClient::processEvent(const FlightStatusEvent& event) {
    std::cout << "Received database event " << event.getNum() << std::endl;
    if (event.getNum() == -1)
        return -1;
    return 0;
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
