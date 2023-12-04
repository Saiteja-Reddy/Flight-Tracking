//
// Created by Sai Teja Reddy Moolamalla on 11/6/23.
//

#include "UIClient.h"

void UIClient::processEvent(const FlightStatusEvent &event) {
    std::cout << "Received UI event " << event << std::endl;
}

UIClient::UIClient() = default;
