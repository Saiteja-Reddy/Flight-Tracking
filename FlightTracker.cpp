//
// Created by Sai Teja Reddy Moolamalla on 11/1/23.
//

#include "FlightTracker.h"

void FlightTracker::registerObserver(const std::shared_ptr<Observer>& observer) {
    observers.push_back(observer);
}

void FlightTracker::removeObserver(const std::shared_ptr<Observer>& observer) {
    auto it = std::find(observers.begin(), observers.end(), observer);
    if (it != observers.end()) {
        observers.erase(it);
    }
}

void FlightTracker::notifyObservers(int i) {
    for(auto& observer: observers) {
        observer->onEvent(i);
    }
}
