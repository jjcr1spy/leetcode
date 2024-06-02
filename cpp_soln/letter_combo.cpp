#include <vector>
#include <string>
#include <unordered_map>

class Solution {
public:
    std::vector<std::string> letterCombinations(std::string digits) {
        if (!digits.size()) return {};

        std::vector<std::string> solution;
        std::string curr;
        std::unordered_map<char, std::string> m = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };

        dfs(solution, curr, digits, m, 0);

        return solution;
    }

    void dfs(std::vector<std::string>& sol, std::string& curr, std::string& digits, std::unordered_map<char, std::string>& m, int index) {
        if (curr.size() == digits.size()) {
            sol.push_back(curr);
            return;
        }
        
        std::string& s = m[digits[index]];

        for (int i = 0; i < s.size(); i++) {
            curr.push_back(s[i]);
            dfs(sol, curr, digits, m, index + 1);
            curr.pop_back();
        }
    }
};