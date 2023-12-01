//
// Created by Sai Teja Reddy Moolamalla on 11/1/23.
//

#ifndef FLIGHT_TRACK_FLIGHTTRACKER_H
#define FLIGHT_TRACK_FLIGHTTRACKER_H


#include <vector>
#include <iostream>
#include "Observable.h"
#include "FlightStatusEvent.h"
#include <unistd.h>

using FlightObserver = Observer<FlightStatusEvent>;

/**
 * Class which tracks flight statuses from the OpenSkyNetwork.
 * See https://openskynetwork.github.io/opensky-api/rest.html
 */
class FlightTracker : public Observable<FlightStatusEvent> {

public:

    void registerObserver(const std::shared_ptr<FlightObserver> &observer) override;

    void unregisterObserver(const std::shared_ptr<FlightObserver> &observer) override;

    void notifyObservers(const FlightStatusEvent &event) override;

    /**
     * Start the flight tracker service
     */
    void start() {
        thread_ = std::thread(&FlightTracker::_main_loop, this);
    }

    /**
     * Stop the flight tracker service
     */
    static void stop() {
        std::terminate();
    }

private:
    std::vector<std::shared_ptr<FlightObserver>> observers;
    std::thread thread_;

    /**
     * Gathers FlightStatusEvent's and notifies the observers. 
     */
    void _main_loop() {
        while (true) {
            sleep(1);
            FlightStatusEvent i = FlightStatusEvent();
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
