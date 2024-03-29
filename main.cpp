#include <iostream>
#include "FlightTracker.h"
#include "DatabaseClient.h"
#include "DummyStatsCollection.h"
#include "FTFrame.h"

#include <wx/wxprec.h>

#ifndef WX_PRECOMP

#include <wx/wx.h>
#include <wx/listctrl.h>

#endif

/**
 * UI App class with wxWidgets for Flight Tracking.
 */
class FlightTrackerApp : public wxApp {
public:
    /**
     * Runs on App init
     * @return error status code
     */
    bool OnInit() override;

    /**
    * Runs on App Exit
    * @return error status code
    */
    int OnExit() override;

private:
    FlightTracker ft;
    std::shared_ptr<DatabaseClient> dc = std::make_shared<DatabaseClient>();
    std::shared_ptr<DummyStatsCollection> uic = std::make_shared<DummyStatsCollection>();
    std::shared_ptr<FTFrame> frame = std::make_shared<FTFrame>("Flight Tracker", wxPoint(50, 50), wxSize(450, 340));
};

wxDEFINE_EVENT(MY_FLIGHT_EVENT, wxFlightEvent);

#define FlightEventHandler(func) (&func)
#define EVT_FLIGHT_STAT(id, func) \
    wx__DECLARE_EVT1(MY_FLIGHT_EVENT, id, FlightEventHandler(func))

wxBEGIN_EVENT_TABLE(FTFrame, wxFrame)
                EVT_FLIGHT_STAT(ID_Flight_Event, FTFrame::OnFlightEvent)
                EVT_MENU(ID_Hello, FTFrame::OnHello)
                EVT_MENU(wxID_EXIT, FTFrame::OnExit)
                EVT_MENU(wxID_ABOUT, FTFrame::OnAbout)
wxEND_EVENT_TABLE()

wxIMPLEMENT_APP(FlightTrackerApp);

bool FlightTrackerApp::OnInit() {
    frame->Show(true);
    ft.registerObserver(dc);
    ft.registerObserver(uic);
    ft.registerObserver(frame);
    dc->start();
    uic->start();
    ft.start();
    return true;
}

int FlightTrackerApp::OnExit() {
    dc->stop();
    uic->stop();
    ft.stop();
    return 0;
}