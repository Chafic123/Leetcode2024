#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        int i = 0, r = 0; // i is the read pointer, r is the write pointer
        int size = chars.size(); // Get the total size of the input vector
        
        while (i < size) {
            int counter = 1; // Start counting repeated characters
            while (i < size - 1 && chars[i] == chars[i + 1]) { // Count consecutive repeated characters
                counter++;
                i++;
            }
            chars[r++] = chars[i++]; // Write the character at index r and increment both i and r
            
            if (counter > 1) { // If there are repetitions
                string num = to_string(counter); // Convert the count to string
                for (char digit : num) { // Write each digit of the count back into the array
                    chars[r++] = digit;
                }
            }
        }
        
        return r; // Return the new length of the array after compression
    }
};
