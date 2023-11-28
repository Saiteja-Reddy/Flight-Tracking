//
// Created by Sai Teja Reddy Moolamalla on 11/28/23.
//

#ifndef FLIGHT_TRACK_FLIGHTSTATUSEVENT_H
#define FLIGHT_TRACK_FLIGHTSTATUSEVENT_H

class FlightStatusEvent {
public:
    FlightStatusEvent(int n) {
        num  = n;
    }

    int getNum() const {
        return num;
    }

private:
    int num;
};

#endif //FLIGHT_TRACK_FLIGHTSTATUSEVENT_H
