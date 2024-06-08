#include <vector>

class Solution {
public:
    int uniquePaths(int m, int n) {
        std::vector<std::vector<int>> dp(m + 1, std::vector(n + 1, 0));
        dp[0][1] = 1;

        for (int i = 1; i < m + 1; ++i) {
            for (int j = 1; j < n + 1; ++j) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        return dp[m][n];
    }
};