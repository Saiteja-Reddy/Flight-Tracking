# Flight-Tracking

Team: Dylan Rose, Gargi Patil, Sai Teja Reddy Moolamalla

## Overview
For our project, our goal is to make and use a well-designed C++ wrapper around an existing API to fetch flight-tracking data. We will be designing a wrapper to expose the REST API to C++ programs with an intuitive interface, and then build a display/UI to demo the functionality and potential use cases for our wrapper. We will include a set of tests for the wrapper, documentation, and measurements regarding the effect the wrapper has on request performance. 

Below are the expected components of our code: 
### Producer component
- Fetches, stores, and publishes flight data from REST API
- The data source is OpenSky REST API: https://openskynetwork.github.io/opensky-api
- Wraps REST API with C++ native classes and functionality
- Periodically polls for changes and publishes the data collected to an event/message queue.

### Consumer component 
- Subscribes to the event queue to which the Producer publishes.
- Below are the two dedicated consumer functionalities we’d be implementing as part of this project:
- Writing the latest data to a database (potentially, SQLite)
- Updating display/UI with new flight information

### UI/Display component
- Flight status dashboard
  - Take input of flight numbers, tracker IDs, or tail numbers.
  - Refreshes continuously based on new events/changes from API
  - The initial state of the dashboard is fetched from the database, then it subscribes to the event queue as events are published from the Producer

## Release Plan/Deliverables

### Release 0.8
- Producer - C++ interface to the REST API, publish events to an event queue.
- Consumer - generic consumer component with a custom implementation for database updates.
- Tutorial, documentation, tests.

### Release 1.0
- Enhanced UI/Display component with an intuitive design.
- Consumer - custom implementation of consumer for UI/display updates.
- Basic display component showing real-time events.

### Release 1.2
- Supporting a map view of the flights with latitude/longitude information of the flights.
- Functionality to add an always-running VM to log flight history internally for specific flights for potential users.

### Testing
- Unit tests - for the C++ client, publishing events, database updates, and display updates.
- Integration test - Publishing few sample events on the queue and making sure it’s updated on the database and display (end-to-end).

### Measurables 
- Currently, no baseline in C++ exists for such an app. We plan to measure the time added due to the wrapper and downstream compute.
- We also plan to stress test the application with an influx of events. 
