#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target) {
        std::sort(candidates.begin(), candidates.end());

        std::vector<std::vector<int>> solution;
        std::vector<int> curr;

        dfs(solution, curr, candidates, target, 0);

        return solution;
    }

    void dfs(std::vector<std::vector<int>>& soln, std::vector<int>& curr, std::vector<int>& candidates, int target, int start) {
        if (target == 0) {
            soln.push_back(curr);
            return;
        } 

        if (target < 0) return;

        for (int i = start; i < candidates.size(); i++) {
            if (i > start && candidates[i] == candidates[i - 1]) continue;

            curr.push_back(candidates[i]);
            dfs(soln, curr, candidates, target - candidates[i], i + 1);
            curr.pop_back();
        }
    }
};