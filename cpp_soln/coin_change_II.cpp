#include <vector>

class Solution {
public:
    int change(int amount, std::vector<int>& coins) {
        int m = coins.size();

        std::vector<std::vector<int>> dp(m, std::vector<int> (amount + 1, -1));

        return dfs(m - 1, amount, coins, dp);
    }

    int dfs(int i, int amount, std::vector<int>& coins, std::vector<std::vector<int>>& dp) {
        if (i < 0 || amount < 0) return 0;
        if (amount == 0) return 1;

        if (dp[i][amount] != -1) return dp[i][amount];

        int with = dfs(i - 1, amount, coins, dp), without = dfs(i, amount - coins[i], coins, dp);

        return dp[i][amount] = with + without;
    }
};