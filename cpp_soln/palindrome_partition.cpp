#include <vector>
#include <string>

class Solution {
public:
    std::vector<std::vector<std::string>> partition(std::string s) {
        std::vector<std::vector<std::string>> solution;
        std::vector<std::string> curr;

        dfs(s, 0, curr, solution);

        return solution;
    }

    bool isPalindrome(const std::string& s, int start, int end) {
        while (start <= end) {
            if (s[start++] != s[end--]) return false;
        }

        return true;
    }

    void dfs(const std::string& s, int start, std::vector<std::string>& curr, std::vector<std::vector<std::string>>& soln) {
        if (start == s.size()) {
            soln.push_back(curr);
            return;
        }

        for (int i = start; i < s.size(); i++) {
            if (isPalindrome(s, start, i)) {
                curr.push_back(s.substr(start, i - start + 1));
                dfs(s, i + 1, curr, soln);
                curr.pop_back();
            }
        }
    }
};