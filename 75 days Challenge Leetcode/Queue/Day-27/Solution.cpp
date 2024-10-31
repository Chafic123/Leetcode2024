#include <queue>

class RecentCounter {
public:
    queue<int> Q; // Queue to store the ping timestamps

    RecentCounter() {
        // Constructor
    }

    int ping(int t) {
        Q.push(t); // Add the current ping timestamp

        // Remove timestamps that are older than 3000 ms from the current ping
        while (!Q.empty() && Q.front() < t - 3000) 
            Q.pop();

        return Q.size(); // Return the number of pings in the last 3000 ms
    }
};


/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */

