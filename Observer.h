//
// Created by Sai Teja Reddy Moolamalla on 11/1/23.
//

#ifndef FLIGHT_TRACK_OBSERVER_H
#define FLIGHT_TRACK_OBSERVER_H


class Observer {
public:
    virtual void onEvent(int num) = 0;

    virtual ~Observer() = default;;
};


#endif //FLIGHT_TRACK_OBSERVER_H
