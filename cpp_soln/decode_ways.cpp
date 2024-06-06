#include <string>
#include <vector>

class Solution {
public:
    int numDecodings(std::string s) {
        if (s[0] == '0') return 0;

        int size = s.size();

        if (size == 1) return 1;

        std::vector<int> dp(size + 1, 0);
        dp[0] = 1;
        dp[1] = 1;

        for (int i = 2; i <= size; ++i) {
            int v = std::stoi(s.substr(i - 1, 1));
            if (v >= 1 && v <= 9) {
                dp[i] += dp[i - 1];
            }

            v = std::stoi(s.substr(i - 2, 2));
            if (v >= 10 && v <= 26) {
                dp[i] += dp[i - 2];
            }    
        }

        return dp[size];
    }
};