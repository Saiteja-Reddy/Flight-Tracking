//
// Created by Sai Teja Reddy Moolamalla on 11/1/23.
//

#include "DatabaseClient.h"

void DatabaseClient::onEvent(int num) {
    std::cout << "Received Event " << num << std::endl;
}

DatabaseClient::DatabaseClient() = default;
