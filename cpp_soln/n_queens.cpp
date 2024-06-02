#include <vector>
#include <string>
#include <unordered_map>

class Solution {
private:
    std::unordered_set<int> cols;     //for Columns
    std::unordered_set<int> negDiag;  //for negative diagnals R-C
    std::unordered_set<int> posDiag;  //for positive diagnals R+C
public:
    std::vector<std::vector<std::string>> solveNQueens(int n) {
        std::vector<std::vector<std::string>> solution;
        std::vector<std::string> curr(n, string(n, '.'));

        dfs(solution, curr, 0, n);

        return solution;
    }

    void dfs(std::vector<std::vector<std::string>>& soln, std::vector<std::string>& curr, int row, int n) {
        if (row == n) {
            soln.push_back(curr);
            return;
        }

        for (int i = 0; i < n; ++i) { // loop through the row, advance column if can place queen
            if (!cols.count(i) && !negDiag.count(row - i) && !posDiag.count(row + i)) {
                curr[row][i] = 'Q';
                cols.insert(i);
                negDiag.insert(row - i);
                posDiag.insert(row + i);


                dfs(soln, curr, row + 1, n);

                curr[row][i] = '.';
                cols.erase(i);
                negDiag.erase(row - i);
                posDiag.erase(row + i);
            }
        }
    }
};