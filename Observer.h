//
// Created by Sai Teja Reddy Moolamalla on 11/1/23.
//

#ifndef FLIGHT_TRACK_OBSERVER_H
#define FLIGHT_TRACK_OBSERVER_H


#include <thread>
#include "SafeQueue.h"

class Observer {
public:
    void onEvent(int num) {
        eventQueue.enqueue(num);
    };

    void start() {
        thread_ = std::thread(&Observer::_event_loop, this);
    };

    virtual int processEvent(int i) = 0;

    void stop() {
        eventQueue.enqueue(-1);
        thread_.join();
    };

    virtual ~Observer() = default;;

private:
    SafeQueue<int> eventQueue;
    std::thread thread_;

    void _event_loop() {
        while (true) {
            int evt = eventQueue.dequeue();
            if (processEvent(evt) == -1)
                break;
        }
    };
};


#endif //FLIGHT_TRACK_OBSERVER_H
