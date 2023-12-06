//
// Created by Sai Teja Reddy Moolamalla on 12/5/23.
//

#include "FTFrame.h"

FTFrame::FTFrame(const wxString &title, const wxPoint &pos, const wxSize &size)
        : wxFrame(nullptr, wxID_ANY, title, pos, size) {

    Bind(MY_FLIGHT_EVENT, &FTFrame::OnFlightEvent, this, ID_Flight_Event);

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
    basicListView->AppendColumn("ICAO24");
    basicListView->AppendColumn("Call Sign");
    basicListView->AppendColumn("Receiver Type");
    basicListView->AppendColumn("Registration");
    basicListView->AppendColumn("Type");
    basicListView->AppendColumn("Longitude");
    basicListView->AppendColumn("Latitude");
    basicListView->AppendColumn("Barometric altitude");
    basicListView->AppendColumn("Geo altitude");
    basicListView->AppendColumn("Nav altitude");
    basicListView->AppendColumn("Ground Speed");
    basicListView->AppendColumn("Indicated Airspeed");
    basicListView->AppendColumn("True Airspeed");
    basicListView->AppendColumn("Outside Air Temp");
    basicListView->AppendColumn("Mag Track");
    basicListView->AppendColumn("True Heading");
    basicListView->AppendColumn("Emergency");
    basicListView->AppendColumn("Category");
    basicListView->AppendColumn("Squawk Code");

    auto sizer = new wxBoxSizer(wxVERTICAL);

    auto button = new wxButton(panel, wxID_ANY, "Show Dialog");
    auto textView = new wxStaticText(panel, wxID_ANY, "Click the button to enter the flight code!");

    sizer->Add(button, 0, wxALL, FromDIP(10));
    sizer->Add(textView, 0, wxALL | wxEXPAND, FromDIP(10));
    sizer->Add(basicListView, 1, wxALL | wxEXPAND, 0);
    panel->SetSizerAndFit(sizer);

    button->Bind(wxEVT_BUTTON, [this, textView](wxCommandEvent &event) {
        auto result = wxGetTextFromUser("Enter your flight number", "Call Sign", "EDV4881");
        textView->SetLabel(result);
    });
}

template<typename T>
requires arithmetic<T>
std::string to_optional_string(const std::optional<T> &val) {
    if (val.has_value()) {
        return std::to_string(val.value());
    } else
        return "-";
}

void FTFrame::addSingleItem(const wxFlightEvent &event, const wxColour &col) {
    int index = basicListView->GetItemCount();
    if (flight_position.count(event.getIcao24()) != 0) {
        index = flight_position[event.getIcao24()];
        basicListView->SetItemBackgroundColour(index, col); // Update color
    } else {
        flight_position[event.getIcao24()] = index;
        basicListView->InsertItem(index, std::to_string(index + 1));
        basicListView->SetItemBackgroundColour(index, *wxGREEN); // Set color to green
    }

    basicListView->SetItem(index, 1, event.getIcao24());
    basicListView->SetItem(index, 2, event.getCallsign().value_or("-"));
    basicListView->SetItem(index, 3, event.getReceiverType().value_or("-"));
    basicListView->SetItem(index, 4, event.getRegistration().value_or("-"));
    basicListView->SetItem(index, 5, event.getType().value_or("-"));
    basicListView->SetItem(index, 6, to_optional_string(event.getLongitude()));
    basicListView->SetItem(index, 7, to_optional_string(event.getLatitude()));
    basicListView->SetItem(index, 8, to_optional_string(event.getBaroAltitude()));
    basicListView->SetItem(index, 9, to_optional_string(event.getGeoAltitude()));
    basicListView->SetItem(index, 10, to_optional_string(event.getNavAltitude()));
    basicListView->SetItem(index, 11, to_optional_string(event.getGroundSpeed()));
    basicListView->SetItem(index, 12, to_optional_string(event.getIndicatedAirspeed()));
    basicListView->SetItem(index, 13, to_optional_string(event.getTrueAirspeed()));
    basicListView->SetItem(index, 14, to_optional_string(event.getOutsideAirTemp()));
    basicListView->SetItem(index, 15, to_optional_string(event.getMagTrack()));
    basicListView->SetItem(index, 16, to_optional_string(event.getTrueHeading()));
    basicListView->SetItem(index, 17, event.getEmergency().value_or("-"));
    basicListView->SetItem(index, 18, event.getCategory().value_or("-"));
    basicListView->SetItem(index, 19, event.getSquawk().value_or("-"));

    // for sorting using the SortItems method
    basicListView->SetItemData(index, index + 1);
}

void FTFrame::OnExit(wxCommandEvent &event) {
    Close(true);
}

void FTFrame::OnAbout(wxCommandEvent &event) {
    wxMessageBox("This is a wxWidgets' Hello world sample",
                 "About Hello World", wxOK | wxICON_INFORMATION);
}

void FTFrame::OnHello(wxCommandEvent &event) {
    std::cout << "Hello called!" << std::endl;
}

void FTFrame::OnFlightEvent(wxFlightEvent &event) {
    auto col = wxColor(gencolor(eng), gencolor(eng), gencolor(eng));
    addSingleItem(event, col);
}

void FTFrame::onEvent(const FlightStatusEvent &event) {
    wxFlightEvent evt(MY_FLIGHT_EVENT, ID_Flight_Event, event);
    wxPostEvent(this, evt);
}