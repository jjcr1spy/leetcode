#include <vector>
#include <algorithm>

class Solution {
public:
    int rob(std::vector<int>& nums) {
        if (nums.size() == 1) return nums[0];

        return std::max(findBest(0, nums.size() - 1, nums), findBest(1, nums.size(), nums));
    }

    int findBest(int start, int end, std::vector<int>& nums) {
        int prev = 0, next = 0, curr = 0;

        for (int i = start; i < end; ++i) {
            next = std::max(nums[i] + prev, curr);
            prev = curr;
            curr = next;
        }

        return next;
    }
};