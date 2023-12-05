//
// Created by Sai Teja Reddy Moolamalla on 12/5/23.
//

#include <wx/wxprec.h>

#ifndef WX_PRECOMP

#include <wx/wx.h>
#include <wx/listctrl.h>

#endif

#include "FlightStatusEvent.h"

#ifndef FLIGHT_TRACK_MYFLIGHTEVENT_H
#define FLIGHT_TRACK_MYFLIGHTEVENT_H

/**
 * Define a new event class to process flight events for the wxFrame UI
 */
class wxFlightEvent : public wxCommandEvent, public FlightStatusEvent {
public:
    /**
     * Constructor
     * @param commandType the event type
     * @param id the event id
     * @param event the received flight status event to be processed
     */
    explicit wxFlightEvent(wxEventType commandType, int id, const FlightStatusEvent &event)
            : wxCommandEvent(commandType, id), FlightStatusEvent(event) {}

    /**
     * Copy constructor
     * @param event the event to be copied
     */
    wxFlightEvent(const wxFlightEvent &event)
            : wxCommandEvent(event), FlightStatusEvent(event) {}

    /**
     * Method to clone this class
     * Required by wxPostEvent()
     * @return the cloned copy
     */
    wxEvent *Clone() const override { return new wxFlightEvent(*this); }
};

#endif //FLIGHT_TRACK_MYFLIGHTEVENT_H
