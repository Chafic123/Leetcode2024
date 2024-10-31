#include <stack>  
#include <vector>  

class Solution {  
public:  
    vector<int> asteroidCollision(vector<int>& asteroids) {  
        stack<int> st;  // Stack to keep track of surviving asteroids

        for (int asteroid : asteroids) {  
            bool destroyed = false;  // Flag to track if the current asteroid is destroyed

            // Check for collisions between the current asteroid and those in the stack
            while (!st.empty() && asteroid < 0 && st.top() > 0) {  
                if (st.top() < abs(asteroid)) {  
                    st.pop(); // The asteroid in the stack is destroyed
                    continue;  
                } else if (st.top() == abs(asteroid)) {
                    st.pop(); // Both asteroids are destroyed
                }
                
                destroyed = true; // Mark the current asteroid as destroyed
                break;  
            }  
            if (!destroyed) st.push(asteroid);  // If not destroyed, push the asteroid onto the stack
        }  

        vector<int> result;  
        while (!st.empty()) {  
            result.push_back(st.top());  // Collect remaining asteroids in result
            st.pop();  
        }  

        reverse(result.begin(), result.end()); // Reverse the result to maintain original order
        return result;  
    }  
};  
