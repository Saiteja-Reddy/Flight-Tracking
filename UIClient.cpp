//
// Created by Sai Teja Reddy Moolamalla on 11/6/23.
//

#include "UIClient.h"

int UIClient::processEvent(int i) {
    std::cout << "Received UI event " << i << std::endl;
    if (i == -1)
        return -1;
}

UIClient::UIClient() = default;
