#include <vector>
#include <algorithm>

class Solution {
public:
    int maxProduct(std::vector<int>& nums) {
        if (nums.size() == 1) return nums[0];

        int min = 1, max = 1, soln = 0;

        for (int i = 0; i < nums.size(); ++i) {
            int temp = max * nums[i];

            max = std::max(std::max(max * nums[i], min * nums[i]), nums[i]);
            min = std::min(std::min(nums[i] * min, temp), nums[i]);

            soln = std::max(soln, max);
        }

        return soln;
    }
};