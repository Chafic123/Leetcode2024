class Solution {
public:
    // Function to merge two strings alternately
    string mergeAlternately(string word1, string word2) {
        // Get the lengths of both input strings
        int len1 = word1.length();
        int len2 = word2.length();
        
        // Initialize an empty string to store the final result
        string result = "";

        // Determine the smaller length between the two strings
        int minlength = len1 < len2 ? len1 : len2;

        // Loop through the characters of both strings up to the length of the shorter one
        for (int i = 0; i < minlength; i++) {
            // Append the character from word1 followed by the character from word2
            result += word1[i];
            result += word2[i];
        }

        // Append the remaining characters from the longer string (if any)
        // If word1 is longer, append the rest of word1
        // If word2 is longer, append the rest of word2
        return (len1 > len2) ? result += word1.substr(minlength)
                             : result += word2.substr(minlength);
    }
};





#ex1(a,b)
def binarySearch(target, lst):
 
  low = 0                        #1
  high = len(lst) - 1            #3
  while low <= high:             #n+1
    mid = (low + high) // 2      #3
    if target == lst[mid]:       #2n
      return mid                 #1
    elif target > lst[mid]:
      low = mid + 1              #2
    else:
      high = mid - 1             #2 --> total number of op(nested if-else) =4n
  return -1                      #1
                                 #--------------------
                                 #T(n)= 5n + 9
                                 #T(n) <= 5n when n >=9
						         #T(n) is O(n) with c = 5 and n0 = 9 
bs plz tshfle bs tkun fade eza fkkret sah?
