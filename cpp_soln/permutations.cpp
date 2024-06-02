#include <vector>
#include <unordered_set>

class Solution {
public:
    std::vector<std::vector<int>> permute(std::vector<int>& nums) {
        std::vector<std::vector<int>> sol;  
        
        dfs(nums, sol, 0);

        return sol;
    }

    void dfs(std::vector<int>& nums, std::vector<std::vector<int>>& sol, int start) {
        if (start == nums.size()) {
            sol.push_back(nums);
            return;
        }

        for (int i = start; i < nums.size(); ++i) {
            std::swap(nums[i], nums[start]);
            dfs(nums, sol, start + 1);
            std::swap(nums[i], nums[start]);
        }
    }
};