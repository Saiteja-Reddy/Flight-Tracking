//
// Created by Sai Teja Reddy Moolamalla on 11/1/23.
//

#ifndef FLIGHT_TRACK_FLIGHTTRACKER_H
#define FLIGHT_TRACK_FLIGHTTRACKER_H


#include <vector>
#include <iostream>
#include "Observable.h"

class FlightTracker : public Observable {
private:

    std::vector<std::shared_ptr<Observer>> observers;

public:

    void registerObserver(const std::shared_ptr<Observer>& observer) override;

    void removeObserver(const std::shared_ptr<Observer>& observer) override;

    void notifyObservers(int i) override;

    void start() {
            thread_ = std::thread(&FlightTracker::_main_loop, this);
    }

private:
    std::thread thread_;

    void _main_loop() {
        while (true) {
            int i;
            std::cin >> i;
            std::cout << "Received evt " << i << std::endl;
            notifyObservers(i);
            if (i == -1) {
                std::cout << "Ending program!" << std::endl;
                break;
            }
        }
    }
};


#endif //FLIGHT_TRACK_FLIGHTTRACKER_H
