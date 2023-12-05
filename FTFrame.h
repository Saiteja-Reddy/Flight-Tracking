//
// Created by Sai Teja Reddy Moolamalla on 12/5/23.
//

#ifndef FLIGHT_TRACK_FTFRAME_H
#define FLIGHT_TRACK_FTFRAME_H

#include <wx/wxprec.h>

#ifndef WX_PRECOMP

#include <wx/wx.h>
#include <wx/listctrl.h>

#endif

#include "FlightStatusEvent.h"
#include "Observer.h"
#include "wxFlightEvent.h"

#include <concepts>
#include <random>

template<typename T>
concept arithmetic = std::integral<T> or std::floating_point<T>;

wxDECLARE_EVENT(MY_FLIGHT_EVENT, wxFlightEvent);

enum {
    ID_Hello = 1,
    ID_Flight_Event = 2
};

/**
 * UI App frame class, which also observers flight status events to update the UI.
 */
class FTFrame : public wxFrame, public Observer<FlightStatusEvent> {
public:
    /**
     * Constructor
     * @param title the UI frame title
     * @param pos position
     * @param size size
     */
    FTFrame(const wxString &title, const wxPoint &pos, const wxSize &size);

    /**
     * Handles UI updates on receiving a flight status event.
     * @param event
     */
    void onEvent(const FlightStatusEvent &event) override;

private:
    /**
     * Function to handle Hello event
     * @param event
     */
    void OnHello(wxCommandEvent &event);

    /**
     * Function to handle Exit
     * @param event
     */
    void OnExit(wxCommandEvent &event);

    /**
     * Function to handle clicking About
     * @param event
     */
    void OnAbout(wxCommandEvent &event);

    /**
     * Helper function to process flight event
     * @param event received flight event
     */
    void OnFlightEvent(wxFlightEvent &event);

    wxListView *basicListView;

    void addSingleItem(const wxFlightEvent &event, const wxColour &col);

    /**
     * Map maintaining the position of flight status record in the UI
     */
    std::map<std::string, int> flight_position;

    /**
     * Initializing random generator for colors on the UI
     */
    std::default_random_engine eng{10};
    std::uniform_int_distribution<> gencolor{124, 247};

wxDECLARE_EVENT_TABLE();
};

#endif //FLIGHT_TRACK_FTFRAME_H
