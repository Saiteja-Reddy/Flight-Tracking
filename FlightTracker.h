//
// Created by Sai Teja Reddy Moolamalla on 11/1/23.
//

#ifndef FLIGHT_TRACK_FLIGHTTRACKER_H
#define FLIGHT_TRACK_FLIGHTTRACKER_H


#include <vector>
#include <iostream>
#include "Observable.h"
#include "FlightStatusEvent.h"
#include "OpenSkyRESTClient.h"
#include <unistd.h>
#include <vector>

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
    OpenSkyRESTClient rest_client = OpenSkyRESTClient();
//    OpenSkyRESTClient rest_client = OpenSkyRESTClient(std::vector<std::string>{"3c6444"});
    /*
     * Above is example of querying base on a specific icao num only. Doesn't seem to work with
     * all icaos, but has always worked with this icao for me
     */

    /**
     * Gathers FlightStatusEvent's and notifies the observers. 
     */
    void _main_loop() {
        while (true) {
            sleep(1);
            FlightStatusEvent i = FlightStatusEvent();
            i.setIcao24("23b4d");
            i.setCallsign("PTR99");
            i.setOriginCountry("USA");
            std::vector<FlightStatusEvent> events = {i};
//            auto events = rest_client.get_events();
            for (auto &event: events) {
                std::cout << "Received evt " << event << std::endl;
                notifyObservers(event);
            }
        }
    }
};


#endif //FLIGHT_TRACK_FLIGHTTRACKER_H
