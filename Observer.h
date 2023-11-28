//
// Created by Sai Teja Reddy Moolamalla on 11/14/23.
//

#ifndef FLIGHT_TRACK_OBSERVER_H
#define FLIGHT_TRACK_OBSERVER_H

template<class T>
class Observer {
public:
    virtual void onEvent(const T& event) = 0;
};


#endif //FLIGHT_TRACK_OBSERVER_H
