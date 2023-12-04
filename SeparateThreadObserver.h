//
// Created by Sai Teja Reddy Moolamalla on 11/1/23.
//

#ifndef FLIGHT_TRACK_SEPARATETHREADOBSERVER_H
#define FLIGHT_TRACK_SEPARATETHREADOBSERVER_H


#include <thread>
#include "SafeQueue.h"
#include "Observer.h"

/**
 * Observer class which has it's own event queue in a separate thread.
 * Upon receiving an event, it is placed in an event queue and returns control.
 * @tparam T type of event observed
 */
template<class T>
class SeparateThreadObserver : public Observer<T> {
public:

    void onEvent(const T &event) override {
        eventQueue.enqueue(event);
    };

    /**
     * Starts the observer
     */
    void start() {
        thread_ = std::thread(&SeparateThreadObserver::_event_loop, this);
    };

    /**
     * Processes the received event
     * @param event the received event
     */
    virtual void processEvent(const T &event) = 0;

    /**
     * Stops the observer
     */
    void stop() {
//        eventQueue.enqueue(T()); // TODO: Either make Queue accept both int and FlightStatusEvent, or make a FlightStatusEvent with stopping command
//        thread_.join();
        std::terminate();
    };

    /**
     * Destructor
     */
    virtual ~SeparateThreadObserver() = default;;

private:
    SafeQueue<T> eventQueue;
    std::thread thread_;

    /**
     * Starts the event loop which fetches events in the queue to process
     */
    void _event_loop() {
        while (true) {
            auto evt = eventQueue.dequeue();
            processEvent(evt);
//            if (processEvent(evt) == -1)
//                break;
        }
    };
};


#endif //FLIGHT_TRACK_SEPARATETHREADOBSERVER_H
