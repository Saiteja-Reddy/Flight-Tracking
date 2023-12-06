//
// Created by Sai Teja Reddy Moolamalla on 11/6/23.
//

#include "DummyStatsCollection.h"

void DummyStatsCollection::processEvent(const FlightStatusEvent &event) {
    number_events++;
    flights.insert(event.getIcao24());
    if (number_events % 1000 == 0) {
        std::cout << "[DummyFlightStats] Number of Events = " << number_events << " - Unique ICAO24: " << flights.size()
                  << std::endl;
    }
}

DummyStatsCollection::DummyStatsCollection() = default;
