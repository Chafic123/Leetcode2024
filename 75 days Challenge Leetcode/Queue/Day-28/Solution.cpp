#include <queue>
#include <string>
using namespace std;

class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> dire;     // Queue to store indices of 'D' (Dire party)
        queue<int> radiant;  // Queue to store indices of 'R' (Radiant party)
        int n = senate.length();

        // Populate the queues with the indices of each party's senators
        for (int i = 0; i < n; i++) {
            if (senate[i] == 'D') 
                dire.push(i);      
            else  
                radiant.push(i);
        }

        // Simulate the process of senators banning each other
        while (!dire.empty() && !radiant.empty()) {
            int r = radiant.front();
            int d = dire.front();
            radiant.pop();
            dire.pop();
            // The one with the smaller index survives and gets to ban the other party's senator
            if (r < d) 
                radiant.push(r + n); // Radiant senator will be at the back of the line after banning
            else 
                dire.push(d + n);     // Dire senator will be at the back of the line after banning
        }

        // Return the winner based on which queue is empty
        return (radiant.empty()) ? "Dire" : "Radiant";
    }
};
