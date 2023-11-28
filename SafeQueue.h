//
// Created by Sai Teja Reddy Moolamalla on 11/6/23.
//

#ifndef FLIGHT_TRACK_SAFEQUEUE_H
#define FLIGHT_TRACK_SAFEQUEUE_H

#include <queue>
#include <mutex>
#include <condition_variable>

// A thread safe queue.
template<class T>
class SafeQueue {
public:
    SafeQueue() : q(), m(), cv() {}

    ~SafeQueue() = default;

    // Add an element to the queue.
    void enqueue(const T& t) {
        std::lock_guard<std::mutex> lock(m);
        q.push(t);
        cv.notify_one();
    }

    // Get the "front"-element.
    // If the queue is empty, wait till a element is available.
    // TODO: memory check? std::move??
    T dequeue() {
        std::unique_lock<std::mutex> lock(m);
        while (q.empty()) {
            // release lock as long as the wait and reacquire it afterwards.
            cv.wait(lock);
        }
        T val = q.front();
        q.pop();
        return val;
    }

private:
    std::queue<T> q;
    mutable std::mutex m;
    std::condition_variable cv;
};

#endif //FLIGHT_TRACK_SAFEQUEUE_H
