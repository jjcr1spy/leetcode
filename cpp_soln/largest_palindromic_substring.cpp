#include <string>

class Solution {
public:
    std::string longestPalindrome(std::string s) {
        int size = s.size();

        int start = 0, length = 1;
        for (int i = 0; i < size; ++i) {
            isPalindrome(i, i, s, start, length);
            isPalindrome(i, i + 1, s, start, length);
        }

        return s.substr(start, length);
    }

    void isPalindrome(int i, int j, std::string& s, int& start, int& length) {
        while (i >= 0 && j <= s.size() - 1 && s[i] == s[j]) {
            --i;
            ++j;
        }

        if (j - i - 1 > length) {
            start = i + 1;
            length = j - i - 1;
        }
    }
};