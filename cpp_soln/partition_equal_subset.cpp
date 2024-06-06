#include <vector>

class Solution {
public:
    bool canPartition(std::vector<int>& nums) {
        int target = 0;

        for (int i = 0; i < nums.size(); ++i) target += nums[i];
        if (target % 2 != 0) return false;

        target /= 2;

        std::vector<int> dp(target + 1, 0);
        dp[0] = 1;    

        for (int i = 0; i < nums.size(); i++) {
            for (int j = target; j >= nums[i]; --j) {
               dp[j] = dp[j] || dp[j - nums[i]]; 
            }
        }
        
        return dp[target];
    }   
};