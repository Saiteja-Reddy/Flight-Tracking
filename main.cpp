#include <iostream>
#include "FlightTracker.h"
#include "DatabaseClient.h"
#include "UIClient.h"

#include <wx/wxprec.h>

#ifndef WX_PRECOMP

#include <wx/wx.h>

#endif

class MyApp : public wxApp {
public:
    virtual bool OnInit();
};

class MyFlightEvent;
wxDECLARE_EVENT(MY_FLIGHT_EVENT, MyFlightEvent);
wxDEFINE_EVENT(MY_FLIGHT_EVENT, MyFlightEvent);

// define a new event class
class MyFlightEvent: public wxCommandEvent
{
public:
    MyFlightEvent(wxEventType commandType = MY_FLIGHT_EVENT, int id = 0)
            :  wxCommandEvent(commandType, id) { }

    // You *must* copy here the data to be transported
    MyFlightEvent(const MyFlightEvent& event)
            :  wxCommandEvent(event) { this->SetNum(event.GetNum()); }

    // accessors
    int GetNum() const { return m_num; }
    void SetNum(int num) { m_num = num; }

    // Required for sending with wxPostEvent()
    wxEvent* Clone() const { return new MyFlightEvent(*this); }

private:
    int m_num;
};

enum {
    ID_Hello = 1,
    ID_Flight_Event = 2
};


class MyFrame : public wxFrame {
public:
    MyFrame(const wxString &title, const wxPoint &pos, const wxSize &size);

private:
    void OnHello(wxCommandEvent &event);

    void OnExit(wxCommandEvent &event);

    void OnAbout(wxCommandEvent &event);

    void OnFlightEvent(MyFlightEvent &event);

wxDECLARE_EVENT_TABLE();
};

#define MyFooEventHandler(func) (&func)
#define EVT_MYFOO(id, func) \
 	wx__DECLARE_EVT1(MY_FLIGHT_EVENT, id, MyFooEventHandler(func))

wxBEGIN_EVENT_TABLE(MyFrame, wxFrame)
EVT_MYFOO(ID_Flight_Event, MyFrame::OnFlightEvent)
EVT_MENU(ID_Hello, MyFrame::OnHello)
EVT_MENU(wxID_EXIT, MyFrame::OnExit)
EVT_MENU(wxID_ABOUT, MyFrame::OnAbout)
wxEND_EVENT_TABLE()

wxIMPLEMENT_APP(MyApp);

FlightTracker ft;
auto dc = std::make_shared<DatabaseClient>();
auto uic = std::make_shared<UIClient>();

bool MyApp::OnInit() {
    MyFrame *frame = new MyFrame("Flight Tracker", wxPoint(50, 50), wxSize(450, 340));
    frame->Show(true);
    ft.registerObserver(dc);
    ft.registerObserver(uic);
    dc->start();
    uic->start();
    ft.start();
    return true;
}

MyFrame::MyFrame(const wxString &title, const wxPoint &pos, const wxSize &size)
        : wxFrame(NULL, wxID_ANY, title, pos, size) {

    Bind(MY_FLIGHT_EVENT, &MyFrame::OnFlightEvent, this, ID_Flight_Event);

    wxMenu *menuFile = new wxMenu;
    menuFile->Append(ID_Hello, "&Hello...\tCtrl-H",
                     "Help string shown in status bar for this menu item");
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT);
    wxMenu *menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);
    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append(menuFile, "&File");
    menuBar->Append(menuHelp, "&Help");
    SetMenuBar(menuBar);
    CreateStatusBar();
    SetStatusText("Welcome to Flight Tracker!");

    auto sizer = new wxBoxSizer(wxVERTICAL);
    auto button = new wxButton(this, wxID_ANY, "Show Dialog");
    auto textView = new wxStaticText(this, wxID_ANY, "Click the button to enter the flight code!");

    sizer->Add(button, 0, wxALL, FromDIP(10));
    sizer->Add(textView, 0, wxALL, FromDIP(10));

    this->SetSizer(sizer);

    button->Bind(wxEVT_BUTTON, [this, textView](wxCommandEvent &event)
    {
        auto result = wxGetTextFromUser("Enter your flight number", "Name", "John Doe");
        textView->SetLabel(result);
    });
}

void MyFrame::OnExit(wxCommandEvent &event) {
    dc->stop();
    uic->stop();
    Close(true);
    std::terminate();
}

void MyFrame::OnAbout(wxCommandEvent &event) {
    wxMessageBox("This is a wxWidgets' Hello world sample",
                 "About Hello World", wxOK | wxICON_INFORMATION);
}

void MyFrame::OnHello(wxCommandEvent &event) {
    MyFlightEvent evt(MY_FLIGHT_EVENT, ID_Flight_Event);
    evt.SetNum(12);
    wxPostEvent(this, evt);
    std::cout << "Hello called!" << std::endl;
}

void MyFrame::OnFlightEvent(MyFlightEvent &event) {
//    wxLogMessage("Hello event from wxWidgets!");
//    wxString msg = wxString::Format("Got Event!  e = %d", event.GetNum());
//    wxMessageBox(msg);
    std::cout << "Got event! - " << event.GetNum() << std::endl;
}

/*
 * https://wiki.wxwidgets.org/Custom_Events
 * https://docs.wxwidgets.org/3.0/page_topics.html
 */