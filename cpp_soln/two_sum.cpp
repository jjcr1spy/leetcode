#include <unordered_map>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> m;

        for (int i = 0; i < nums.size(); i++) {
            int k = target - nums[i];

            if (m.count(k) == 0) m[nums[i]] = i;
            else return {m[k], i};
        }     

        return {};
    }
};