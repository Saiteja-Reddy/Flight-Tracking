//
// Created by Sai Teja Reddy Moolamalla on 11/1/23.
//

#ifndef FLIGHT_TRACK_FLIGHTTRACKER_H
#define FLIGHT_TRACK_FLIGHTTRACKER_H


#include <vector>
#include <iostream>
#include "Observable.h"
#include "FlightStatusEvent.h"
#include<unistd.h>

using FlightObserver = Observer<FlightStatusEvent>;
class FlightTracker : public Observable<FlightStatusEvent> {
private:

    std::vector<std::shared_ptr<FlightObserver>> observers;

public:

    void registerObserver(const std::shared_ptr<FlightObserver>& observer) override;

    void removeObserver(const std::shared_ptr<FlightObserver>& observer) override;

    void notifyObservers(const FlightStatusEvent& event) override;

    void start() {
            thread_ = std::thread(&FlightTracker::_main_loop, this);
    }

    static void stop() {
        std::terminate();
    }

private:
    std::thread thread_;

    void _main_loop() {
        while (true) {
            sleep(1);
            auto i = FlightStatusEvent(rand() % 1000);
            std::cout << "Received evt " << i.getNum() << std::endl;
            notifyObservers(i);
            if (i.getNum() == -1) {
                std::cout << "Ending program!" << std::endl;
                break;
            }
        }
    }
};


#endif //FLIGHT_TRACK_FLIGHTTRACKER_H
