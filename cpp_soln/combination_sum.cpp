#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
        std::vector<std::vector<int>> sol;
        std::vector<int> curr;
        
        dfs(candidates, target, sol, curr, 0);

        return sol;
    }

    void dfs(std::vector<int>& candidates, int target, std::vector<std::vector<int>>& sol, std::vector<int>& curr, int i) {
        if (target == 0) {
            sol.push_back(curr);
            return;
        } 
        
        if (i >= candidates.size() || target < 0) return; 
        
        curr.push_back(candidates[i]);

        dfs(candidates, target - candidates[i], sol, curr, i);

        curr.pop_back();

        dfs(candidates, target, sol, curr, i + 1);
    }
};