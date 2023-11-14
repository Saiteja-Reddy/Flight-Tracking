//
// Created by Sai Teja Reddy Moolamalla on 11/1/23.
//

#ifndef FLIGHT_TRACK_SEPARATETHREADOBSERVER_H
#define FLIGHT_TRACK_SEPARATETHREADOBSERVER_H


#include <thread>
#include "SafeQueue.h"
#include "Observer.h"

class SeparateThreadObserver : public Observer {
public:
    void onEvent(int num) override {
        eventQueue.enqueue(num);
    };

    void start() {
        thread_ = std::thread(&SeparateThreadObserver::_event_loop, this);
    };

    virtual int processEvent(int i) = 0;

    void stop() {
        eventQueue.enqueue(-1);
        thread_.join();
    };

    virtual ~SeparateThreadObserver() = default;;

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


#endif //FLIGHT_TRACK_SEPARATETHREADOBSERVER_H
