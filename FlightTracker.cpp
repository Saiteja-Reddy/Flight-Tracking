//
// Created by Sai Teja Reddy Moolamalla on 11/1/23.
//

#include "FlightTracker.h"

void FlightTracker::registerObserver(const std::shared_ptr<FlightObserver>& observer) {
    observers.push_back(observer);
}

void FlightTracker::unregisterObserver(const std::shared_ptr<FlightObserver>& observer) {
    auto it = std::find(observers.begin(), observers.end(), observer);
    if (it != observers.end()) {
        observers.erase(it);
    }
}

void FlightTracker::notifyObservers(const FlightStatusEvent& event) {
    for(auto& observer: observers) {
        observer->onEvent(event);
    }
}
