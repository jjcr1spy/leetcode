#include <vector>
#include <algorithm>

class Solution {
public:
    int rob(std::vector<int>& nums) {
        int prev = 0, next = 0, curr = 0;

        for (int i = 0; i < nums.size(); ++i) {
            next = std::max(nums[i] + prev, curr);
            prev = curr;
            curr = next;
        }

        return next;
    }
};