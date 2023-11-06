//
// Created by Sai Teja Reddy Moolamalla on 11/6/23.
//

#ifndef FLIGHT_TRACK_UICLIENT_H
#define FLIGHT_TRACK_UICLIENT_H

#include <iostream>
#include "Observer.h"

class UIClient : public Observer {
public:
    UIClient();

    int processEvent(int i) override;
};


#endif //FLIGHT_TRACK_UICLIENT_H
