//
// Created by Sai Teja Reddy Moolamalla on 11/6/23.
//

#ifndef FLIGHT_TRACK_DUMMYSTATSCOLLECTION_H
#define FLIGHT_TRACK_DUMMYSTATSCOLLECTION_H

#include <iostream>
#include <set>
#include "SeparateThreadObserver.h"
#include "FlightStatusEvent.h"

/**
 * An Observer class which updates the Stats
 */
class DummyStatsCollection : public SeparateThreadObserver<FlightStatusEvent> {
public:
    /**
     * Constructor
     */
    DummyStatsCollection();

    /**
     * Function which processes the received flight status event.
     * Updates the stats collection with the new flight status.
     * @param event received flight status
     */
    void processEvent(const FlightStatusEvent &event) override;

private:
    long long number_events = 0;
    std::set<std::string> flights;
};


#endif //FLIGHT_TRACK_DUMMYSTATSCOLLECTION_H
