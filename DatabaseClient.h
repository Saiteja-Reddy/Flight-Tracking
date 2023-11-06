//
// Created by Sai Teja Reddy Moolamalla on 11/1/23.
//

#ifndef FLIGHT_TRACK_DATABASECLIENT_H
#define FLIGHT_TRACK_DATABASECLIENT_H

#include <iostream>
#include "Observer.h"

class DatabaseClient : public Observer {
public:
    DatabaseClient();

    int processEvent(int i) override;
};


#endif //FLIGHT_TRACK_DATABASECLIENT_H
