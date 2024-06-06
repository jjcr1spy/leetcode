#include <string>

class Solution {
public:
    int countSubstrings(std::string s) {
        int count = 0;

        for (int i = 0; i < s.size(); ++i) {
            countPalindrome(i, i, s, count);
            countPalindrome(i, i + 1, s, count);
        }

        return count;
    }

    void countPalindrome(int i, int j, std::string& s, int& count) {
        while (i >= 0 && j <= s.size() - 1 && s[i] == s[j]) {
            --i;
            ++j;
            ++count;
        }
    }
};