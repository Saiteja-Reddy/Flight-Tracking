//
// Created by Sai Teja Reddy Moolamalla on 11/1/23.
//

#ifndef FLIGHT_TRACK_FLIGHTTRACKER_H
#define FLIGHT_TRACK_FLIGHTTRACKER_H


#include <vector>
#include "Observable.h"

class FlightTracker : public Observable {
private:

    std::vector<std::shared_ptr<Observer>> observers;

public:

    void registerObserver(std::shared_ptr<Observer> observer) override;

    void removeObserver(std::shared_ptr<Observer> observer) override;

    void notifyObservers() override;
};


#endif //FLIGHT_TRACK_FLIGHTTRACKER_H
