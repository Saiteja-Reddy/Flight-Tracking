//
// Created by Sai Teja Reddy Moolamalla on 11/1/23.
//

#ifndef FLIGHT_TRACK_OBSERVABLE_H
#define FLIGHT_TRACK_OBSERVABLE_H


#include <memory>
#include "Observer.h"

class Observable {
public:
    // TODO: check the design of passing shared_ptr's?
    virtual void registerObserver(std::shared_ptr<Observer> observer) = 0;
    virtual void removeObserver(std::shared_ptr<Observer> observer) = 0;
    virtual void notifyObservers() = 0;
};


#endif //FLIGHT_TRACK_OBSERVABLE_H
