cmake_minimum_required(VERSION 3.23)
project(flight_track)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/thirdparty/SQLiteCpp)
add_executable(flight_track main.cpp Observer.h DatabaseClient.cpp DatabaseClient.h Observable.h FlightTracker.cpp FlightTracker.h SafeQueue.h UIClient.cpp UIClient.h)
target_link_libraries(flight_track
        SQLiteCpp
        sqlite3
        pthread
        dl
        )
