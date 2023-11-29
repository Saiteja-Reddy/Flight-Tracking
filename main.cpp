#include <iostream>
#include "FlightTracker.h"
#include "DatabaseClient.h"
#include "UIClient.h"

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
    bool OnInit() override;
};

class MyFlightEvent;

wxDECLARE_EVENT(MY_FLIGHT_EVENT, MyFlightEvent);
wxDEFINE_EVENT(MY_FLIGHT_EVENT, MyFlightEvent);

/**
 * Define a new event class
 */
class MyFlightEvent : public wxCommandEvent {
public:
    explicit MyFlightEvent(wxEventType commandType = MY_FLIGHT_EVENT, int id = 0)
            : wxCommandEvent(commandType, id) {}

    // You *must* copy here the data to be transported
    MyFlightEvent(const MyFlightEvent &event)
            : wxCommandEvent(event) { this->SetNum(event.GetNum()); }

    // accessors
    int GetNum() const { return m_num; }

    void SetNum(int num) { m_num = num; }

    // Required for sending with wxPostEvent()
    wxEvent *Clone() const override { return new MyFlightEvent(*this); }

private:
    int m_num{};
};

enum {
    ID_Hello = 1,
    ID_Flight_Event = 2
};


/**
 * UI App frame class, which also observers flight status events to update the UI.
 */
class MyFrame : public wxFrame, public Observer<FlightStatusEvent> {
public:
    MyFrame(const wxString &title, const wxPoint &pos, const wxSize &size);

    void onEvent(const FlightStatusEvent &event) override;

private:
    void OnHello(wxCommandEvent &event);

    void OnExit(wxCommandEvent &event);

    void OnAbout(wxCommandEvent &event);

    void OnFlightEvent(MyFlightEvent &event);

    wxListView *basicListView;

    void populateListView();

    void addSingleItem(int id, const std::string &name, const std::string &description);

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

MyFrame::MyFrame(const wxString &title, const wxPoint &pos, const wxSize &size)
        : wxFrame(nullptr, wxID_ANY, title, pos, size) {

    Bind(MY_FLIGHT_EVENT, &MyFrame::OnFlightEvent, this, ID_Flight_Event);

    auto *menuFile = new wxMenu;
    menuFile->Append(ID_Hello, "&Hello...\tCtrl-H",
                     "Help string shown in status bar for this menu item");
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT);
    auto *menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);
    auto *menuBar = new wxMenuBar;
    menuBar->Append(menuFile, "&File");
    menuBar->Append(menuHelp, "&Help");
    SetMenuBar(menuBar);
    CreateStatusBar();
    SetStatusText("Welcome to Flight Tracker!");

    auto *panel = new wxPanel(this);
    basicListView = new wxListView(panel);
    basicListView->AppendColumn("ID");
    basicListView->AppendColumn("Name");
    basicListView->AppendColumn("Description");
    basicListView->SetColumnWidth(0, 80);
    basicListView->SetColumnWidth(1, 120);
    basicListView->SetColumnWidth(2, 600);

    auto sizer = new wxBoxSizer(wxVERTICAL);

    auto button = new wxButton(panel, wxID_ANY, "Show Dialog");
    auto textView = new wxStaticText(panel, wxID_ANY, "Click the button to enter the flight code!");

    sizer->Add(button, 0, wxALL, FromDIP(10));
    sizer->Add(textView, 0, wxALL | wxEXPAND, FromDIP(10));
    sizer->Add(basicListView, 1, wxALL | wxEXPAND, 0);
    panel->SetSizerAndFit(sizer);
    populateListView();

    button->Bind(wxEVT_BUTTON, [this, textView](wxCommandEvent &event) {
        auto result = wxGetTextFromUser("Enter your flight number", "Name", "John Doe");
        textView->SetLabel(result);
    });
}

void MyFrame::populateListView() {
    addSingleItem(123, "Some Item", "This is an item");
    addSingleItem(456, "Other Item", "A different item");
    addSingleItem(102, "Another Item", "The best one!");
}

void MyFrame::addSingleItem(int id, const std::string &name, const std::string &description) {
    int index = basicListView->GetItemCount();

    basicListView->InsertItem(index, std::to_string(id));
    basicListView->SetItem(index, 1, name);
    basicListView->SetItem(index, 2, description);

    // for sorting using the SortItems method
    basicListView->SetItemData(index, id);
}

void MyFrame::OnExit(wxCommandEvent &event) {
    dc->stop();
    uic->stop();
    Close(true);
    ft.stop();
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
    std::cout << "Got event! - " << event.GetNum() << std::endl;
    addSingleItem(event.GetNum(), "Test Flight Item", "Item Desc");
}

void MyFrame::onEvent(const FlightStatusEvent &event) {
    MyFlightEvent evt(MY_FLIGHT_EVENT, ID_Flight_Event);
    evt.SetNum(event.getNum());
    wxPostEvent(this, evt);
}