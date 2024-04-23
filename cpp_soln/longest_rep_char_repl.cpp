#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    int characterReplacement(std::string s, int k) {
        int l = s.length();
        
        if (l == 1) return 1;

        std::vector<int> v(26, 0);
        int i = 0, j = 0, max = 0, max_count = 0;

        while (j < l) { // we want to extend window as far as we can given i, j, k, and max_count
            v[s[j] - 'A']++;
            max_count = std::max(max_count, v[s[j] - 'A']);
    
            // once window is as big as it can get, we start shifting the window to find possible better solns
            if (j - i + 1 - max_count > k) {
                v[s[i] - 'A']--;
                i++; 
            } 
            
            max = std::max(max, j - i + 1); // update max
            j++;
        }

        return max;
    }
};