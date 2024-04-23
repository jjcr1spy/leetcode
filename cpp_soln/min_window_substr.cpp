#include <string>
#include <vector>
#include <unordered_map>
#include <climits>

class Solution {
public:
    std::string minWindow(std::string s, std::string t) {
        if (s.size() < t.size()) return {""};
        
        std::unordered_map<char, int> m;
        for (int i = 0; i < t.size(); ++i) {
            m[t[i]]++;
        }
        
        int start = 0, min_window = INT_MAX, count = t.size();
        int i = 0, j = 0;

        while (j < s.size()) {
            if (m[s[j]] > 0) count--;
            
            m[s[j]]--; // will be negative if not in substr, also handles dup cases
            j++; // increment j 

            while (count == 0) {
                if (j - i < min_window) {
                    start = i;
                    min_window = j - i;
                }

                m[s[i]]++;
               
                if (m[s[i]] > 0) {
                    count++;
                }

                i++;
            }
        }
        
        return min_window == INT_MAX ? "" : s.substr(start, min_window);
    }
};