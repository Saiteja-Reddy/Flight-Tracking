#include <iostream>
#include "FlightTracker.h"
#include "DatabaseClient.h"
#include "UIClient.h"

int main() {
    std::cout << "Hello World!" << std::endl;

    FlightTracker ft;
    auto dc = std::make_shared<DatabaseClient>();
    auto uic = std::make_shared<UIClient>();
    ft.registerObserver(dc);
    ft.registerObserver(uic);

    dc->start();
    uic->start();

    ft.start();

    dc->stop();
    uic->stop();
    return 0;
}
