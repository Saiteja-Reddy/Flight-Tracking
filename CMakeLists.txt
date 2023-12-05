cmake_minimum_required(VERSION 3.23)
project(flight_track)

set(CMAKE_CXX_STANDARD 20)

set(OPENSSL_ROOT_DIR $ENV{OPENSSL_ROOT_DIR})
set(OPENSSL_INCLUDE_DIR $ENV{OPENSSL_INCLUDE_DIR})
set(CPPRESTSDK_INCLUDE_DIR "/opt/homebrew/Cellar/cpprestsdk/2.10.18_1/include")

find_package(OpenSSL REQUIRED)
find_package(cpprestsdk REQUIRED)
find_package(wxWidgets REQUIRED COMPONENTS net core base)
if(wxWidgets_USE_FILE) # not defined in CONFIG mode
    include(${wxWidgets_USE_FILE})
endif()

add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/thirdparty/SQLiteCpp)

# first we can indicate the documentation build as an option and set it to ON by default
option(BUILD_DOC "Build documentation" ON)

# check if Doxygen is installed
find_package(Doxygen)

if (DOXYGEN_FOUND)
    # set input and output files
    set(DOXYGEN_IN ${CMAKE_CURRENT_SOURCE_DIR}/docs/Doxyfile.in)
    set(DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)

    # request to configure the file
    configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)
    message("Doxygen build started")

    # note the option ALL which allows to build the docs together with the application
    add_custom_target(doc_doxygen ALL
            COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
            WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
            COMMENT "Generating API documentation with Doxygen"
            VERBATIM )
else (DOXYGEN_FOUND)
    message("Doxygen need to be installed to generate the doxygen documentation")
endif (DOXYGEN_FOUND)

add_executable(flight_track main.cpp
        SeparateThreadObserver.h
        DatabaseClient.cpp DatabaseClient.h
        Observable.h
        FlightTracker.cpp FlightTracker.h
        SafeQueue.h
        UIClient.cpp UIClient.h
        Observer.h
        FlightStatusEvent.h FlightStatusEvent.cpp
        ADSBlolRESTClient.cpp ADSBlolRESTClient.h
        FTFrame.cpp FTFrame.h
        wxFlightEvent.h)

target_link_libraries(flight_track
        SQLiteCpp
        sqlite3
        pthread
        dl
        ${wxWidgets_LIBRARIES}
        cpprestsdk::cpprest
        OpenSSL::SSL
        )