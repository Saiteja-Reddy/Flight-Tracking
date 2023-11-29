//
// Created by Sai Teja Reddy Moolamalla on 11/14/23.
//

#ifndef FLIGHT_TRACK_OBSERVER_H
#define FLIGHT_TRACK_OBSERVER_H

/**
 * Class which observes and acts on events sent from an Observable
 * @tparam T type of event observed
 */
template<class T>
class Observer {
public:
    /**
     * Processes an event received from an Observable
     * @param event The event sent from an Observable
     */
    virtual void onEvent(const T &event) = 0;
};


#endif //FLIGHT_TRACK_OBSERVER_H
