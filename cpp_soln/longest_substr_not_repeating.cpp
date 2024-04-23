#include <string>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        int l = s.length();

        if (l == 0) return 0;
        if (l == 1) return 1;

        std::unordered_map<char, int> m;
        int i = 0, j = 0, max = 1;

        while (j < l) {
            if (m.count(s[j])) {
                i = std::max(m[s[j]] + 1, i);
            }

            m[s[j]] = j;
            max = std::max(j - i + 1, max);
            j++;
        }

        return max;
    }
};