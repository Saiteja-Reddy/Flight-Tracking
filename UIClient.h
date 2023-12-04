//
// Created by Sai Teja Reddy Moolamalla on 11/6/23.
//

#ifndef FLIGHT_TRACK_UICLIENT_H
#define FLIGHT_TRACK_UICLIENT_H

#include <iostream>
#include "SeparateThreadObserver.h"
#include "FlightStatusEvent.h"

/**
 * An Observer class which updates the UI
 */
class UIClient : public SeparateThreadObserver<FlightStatusEvent> {
public:
    /**
     * Constructor
     */
    UIClient();

    /**
     * Function which processes the received flight status event.
     * Updates the UI with the new flight status.
     * @param event received flight status
     */
    void processEvent(const FlightStatusEvent &event) override;
};


#endif //FLIGHT_TRACK_UICLIENT_H
