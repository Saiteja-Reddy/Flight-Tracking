//
// Created by Sai Teja Reddy Moolamalla on 11/1/23.
//

#ifndef FLIGHT_TRACK_OBSERVABLE_H
#define FLIGHT_TRACK_OBSERVABLE_H


#include <memory>
#include "SeparateThreadObserver.h"

// TODO: use concepts here to check for template args type?
template<class T>
class Observable {
public:
    // TODO: check the design of passing shared_ptr's?
    virtual void registerObserver(const std::shared_ptr<Observer<T>>& observer) = 0;
    virtual void removeObserver(const std::shared_ptr<Observer<T>>& observer) = 0;
    virtual void notifyObservers(const T& event) = 0;

    virtual ~Observable() = default;
};


#endif //FLIGHT_TRACK_OBSERVABLE_H
