#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> subsetsWithDup(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());

        std::vector<std::vector<int>> solution;
        std::vector<int> curr;

        dfs(solution, nums, curr, 0);

        return solution;
    }

    void dfs(std::vector<std::vector<int>>& soln, std::vector<int>& nums, std::vector<int>& curr, int start) {
        soln.push_back(curr);

        for (int i = start; i < nums.size(); ++i) {
            if (i > start && nums[i] == nums[i - 1]) continue;
            
            curr.push_back(nums[i]);
            dfs(soln, nums, curr, i + 1);
            curr.pop_back();
        }
    }
};