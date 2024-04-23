#include <string>
#include <vector>

class Solution {
public:
    bool checkInclusion(std::string s1, std::string s2) {
        if (s1.size() > s2.size()) {
            return false;
        }

        std::vector<int> v1(26, 0), v2(26, 0);

        // Count frequencies of characters in s1
        for (char c : s1) {
            v1[c - 'a']++;
        }

        int l1 = s1.size(), l2 = s2.size();
        int count = l1; // Initialize count to the length of s1

        // Initialize the sliding window
        for (int i = 0; i < l1; i++) {
            v2[s2[i] - 'a']++;
            if (v2[s2[i] - 'a'] <= v1[s2[i] - 'a']) {
                count--; // Decrement count if the character in s2 is in s1
            }
        }

        // Check if the initial window of s2 is a permutation of s1
        if (count == 0) {
            return true;
        }

        // Slide the window through s2 and update the frequency counts
        for (int i = l1; i < l2; i++) {
            // Include the new character
            v2[s2[i] - 'a']++;
            if (v2[s2[i] - 'a'] <= v1[s2[i] - 'a']) {
                count--; // Decrement count if the character in s2 is in s1
            }

            // Exclude the character that falls out of the window
            v2[s2[i - l1] - 'a']--;
            if (v2[s2[i - l1] - 'a'] < v1[s2[i - l1] - 'a']) {
                count++; // Increment count if the character in s2 is no longer in the window
            }

            // Check if the current window of s2 is a permutation of s1
            if (count == 0) {
                return true;
            }
        }

        return false;
    }
};