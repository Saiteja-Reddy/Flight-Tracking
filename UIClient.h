//
// Created by Sai Teja Reddy Moolamalla on 11/6/23.
//

#ifndef FLIGHT_TRACK_UICLIENT_H
#define FLIGHT_TRACK_UICLIENT_H

#include <iostream>
#include "SeparateThreadObserver.h"
#include "FlightStatusEvent.h"

class UIClient : public SeparateThreadObserver<FlightStatusEvent> {
public:
    UIClient();

    int processEvent(const FlightStatusEvent& event) override;
};


#endif //FLIGHT_TRACK_UICLIENT_H
