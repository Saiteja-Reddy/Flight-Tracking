//
// Created by Sai Teja Reddy Moolamalla on 11/1/23.
//

#ifndef FLIGHT_TRACK_OBSERVABLE_H
#define FLIGHT_TRACK_OBSERVABLE_H


#include <memory>
#include "SeparateThreadObserver.h"

/**
 * Class to notify events to registered observers
 * @tparam T type of event
 */
template<class T>
class Observable {
public:

    /**
     * Register the observer with the observable
     * @param observer The observer to be registered
     */
    virtual void registerObserver(const std::shared_ptr<Observer<T>> &observer) = 0;

    /**
     * Unregister the observer with the observable
     * @param observer The observer to be unregistered
     */
    virtual void unregisterObserver(const std::shared_ptr<Observer<T>> &observer) = 0;

    /**
     * Notify the observers with the input event
     * @param event The event to be sent to the observers
     */
    virtual void notifyObservers(const T &event) = 0;

    /**
     * Destructor
     */
    virtual ~Observable() = default;
};


#endif //FLIGHT_TRACK_OBSERVABLE_H
