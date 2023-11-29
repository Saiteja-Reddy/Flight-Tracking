//
// Created by Sai Teja Reddy Moolamalla on 11/6/23.
//

#include "UIClient.h"

int UIClient::processEvent(const FlightStatusEvent &event) {
    std::cout << "Received UI event " << event.getNum() << std::endl;
    if (event.getNum() == -1)
        return -1;
    return 0;
}

UIClient::UIClient() = default;
