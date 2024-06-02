#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
        std::vector<int> curr;
        std::vector<std::vector<int>> result;

        dfs(nums, 0, curr, result);

        return result;
    }
private:
    void dfs(std::vector<int>& nums, int start, std::vector<int>& curr, std::vector<std::vector<int>>& result) {
        result.push_back(curr);

        for (int i = start; i < nums.size(); i++) {
            curr.push_back(nums[i]);

            dfs(nums, i + 1, curr, result);
            
            curr.pop_back();
        }
    }
};
