#include <iostream>
#include "FlightTracker.h"
#include "DatabaseClient.h"
#include "UIClient.h"
#include "MyFrame.h"

#include <wx/wxprec.h>

#ifndef WX_PRECOMP

#include <wx/wx.h>
#include <wx/listctrl.h>

#endif

/**
 * UI App class with wxWidgets.
 */
class MyApp : public wxApp {
public:
    /**
     * Runs on App init
     * @return error status code
     */
    bool OnInit() override;

    int OnExit() override;
};

wxDEFINE_EVENT(MY_FLIGHT_EVENT, MyFlightEvent);

#define FlightEventHandler(func) (&func)
#define EVT_FLIGHT_STAT(id, func) \
    wx__DECLARE_EVT1(MY_FLIGHT_EVENT, id, FlightEventHandler(func))

wxBEGIN_EVENT_TABLE(MyFrame, wxFrame)
                EVT_FLIGHT_STAT(ID_Flight_Event, MyFrame::OnFlightEvent)
                EVT_MENU(ID_Hello, MyFrame::OnHello)
                EVT_MENU(wxID_EXIT, MyFrame::OnExit)
                EVT_MENU(wxID_ABOUT, MyFrame::OnAbout)
wxEND_EVENT_TABLE()

wxIMPLEMENT_APP(MyApp);

FlightTracker ft;
auto dc = std::make_shared<DatabaseClient>();
auto uic = std::make_shared<UIClient>();

bool MyApp::OnInit() {
    auto *frame = new MyFrame("Flight Tracker", wxPoint(50, 50), wxSize(450, 340));
    frame->Show(true);
    ft.registerObserver(dc);
    ft.registerObserver(uic);
    ft.registerObserver(std::shared_ptr<MyFrame>(frame));
    dc->start();
    uic->start();
    ft.start();
    return true;
}

int MyApp::OnExit() {
    dc->stop();
    uic->stop();
    ft.stop();
    return 0;
}