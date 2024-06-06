#include <string>
#include <vector>
#include <unordered_set>

class Solution {
public:
    bool wordBreak(std::string s, std::vector<std::string>& wordDict) {
        int n = s.size();

        std::vector<int> dp(n + 1, 0);
        dp[0] = true;

        std::unordered_set<std::string> set(wordDict.begin(), wordDict.end());

        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (dp[j] && set.count(s.substr(j, i - j))) {
                    dp[i] = true; 
                    break;
                }
            }
        }

        return dp[n];
    }
};