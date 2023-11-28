//
// Created by Sai Teja Reddy Moolamalla on 11/1/23.
//

#ifndef FLIGHT_TRACK_SEPARATETHREADOBSERVER_H
#define FLIGHT_TRACK_SEPARATETHREADOBSERVER_H


#include <thread>
#include "SafeQueue.h"
#include "Observer.h"

template<class T>
class SeparateThreadObserver : public Observer<T> {
public:
    void onEvent(const T& event) override {
        eventQueue.enqueue(event);
    };

    void start() {
        thread_ = std::thread(&SeparateThreadObserver::_event_loop, this);
    };

    virtual int processEvent(const T& event) = 0;

    void stop() {
        eventQueue.enqueue(-1);
        thread_.join();
    };

    virtual ~SeparateThreadObserver() = default;;

private:
    SafeQueue<T> eventQueue;
    std::thread thread_;

    void _event_loop() {
        while (true) {
            auto evt = eventQueue.dequeue();
            if (processEvent(evt) == -1)
                break;
        }
    };
};


#endif //FLIGHT_TRACK_SEPARATETHREADOBSERVER_H
