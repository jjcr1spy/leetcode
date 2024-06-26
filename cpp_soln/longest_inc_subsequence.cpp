#include <vector>
#include <algorithm>

class Solution {
public:
    int lengthOfLIS(std::vector<int>& nums) {
        std::vector<int> dp;
        dp.push_back(nums[0]);

        for (int i = 1; i < nums.size(); ++i) {
            if (dp.back() < nums[i]) {
                dp.push_back(nums[i]);
            } else {
                std::vector<int>::iterator it = std::lower_bound(dp.begin(), dp.end(), nums[i]);
                *it = nums[i];
            }
        }

        return dp.size();
    }
};