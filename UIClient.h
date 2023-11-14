//
// Created by Sai Teja Reddy Moolamalla on 11/6/23.
//

#ifndef FLIGHT_TRACK_UICLIENT_H
#define FLIGHT_TRACK_UICLIENT_H

#include <iostream>
#include "SeparateThreadObserver.h"

class UIClient : public SeparateThreadObserver {
public:
    UIClient();

    int processEvent(int i) override;
};


#endif //FLIGHT_TRACK_UICLIENT_H
