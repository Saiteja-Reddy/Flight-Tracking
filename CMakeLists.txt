cmake_minimum_required(VERSION 3.23)
project(flight_track)

set(CMAKE_CXX_STANDARD 20)

set(OPENSSL_ROOT_DIR "/opt/homebrew/Cellar/openssl@3/3.0.7")
set(OPENSSL_INCLUDE_DIR "/opt/homebrew/Cellar/openssl@3/3.0.7/include")
find_package(OpenSSL REQUIRED)

find_package(cpprestsdk REQUIRED)

find_package(wxWidgets REQUIRED COMPONENTS net core base)
if(wxWidgets_USE_FILE) # not defined in CONFIG mode
    include(${wxWidgets_USE_FILE})
endif()

add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/thirdparty/SQLiteCpp)
add_executable(flight_track main.cpp SeparateThreadObserver.h DatabaseClient.cpp DatabaseClient.h Observable.h FlightTracker.cpp FlightTracker.h SafeQueue.h UIClient.cpp UIClient.h Observer.h FlightStatusEvent.h
        FlightStatusEvent.cpp)
target_link_libraries(flight_track
        SQLiteCpp
        sqlite3
        pthread
        dl
        ${wxWidgets_LIBRARIES}
        cpprestsdk::cpprest
        OpenSSL::SSL
        )
