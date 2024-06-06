#include <vector>
#include <algorithm>
#include <climits>

class Solution {
public:
    int coinChange(std::vector<int>& coins, int amount) {
        if (amount == 0) return 0;

        std::vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;

        for (int i = 1; i < amount + 1; ++i) {
             for (int j = 0; j < coins.size(); ++j) {
                if (i - coins[j] >= 0 && dp[i - coins[j]] != INT_MAX) {
                    dp[i] = std::min(dp[i], dp[i - coins[j]] + 1);
                }
             }   
        }


        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};