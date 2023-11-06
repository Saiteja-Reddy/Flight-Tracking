cmake_minimum_required(VERSION 3.23)
project(flight_track)

set(CMAKE_CXX_STANDARD 20)

add_executable(flight_track main.cpp Observer.h DatabaseClient.cpp DatabaseClient.h Observable.h FlightTracker.cpp FlightTracker.h SafeQueue.h UIClient.cpp UIClient.h)
