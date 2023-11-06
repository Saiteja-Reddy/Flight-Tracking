//
// Created by Sai Teja Reddy Moolamalla on 11/1/23.
//

#include "DatabaseClient.h"


DatabaseClient::DatabaseClient() = default;

int DatabaseClient::processEvent(int i) {
    std::cout << "Received database event " << i << std::endl;
    if (i == -1)
        return -1;
}
