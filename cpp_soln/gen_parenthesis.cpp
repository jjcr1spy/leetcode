#include <vector>
#include <string>

class Solution {
public:
    std::vector<std::string> generateParenthesis(int n) {
        std::vector<std::string> comb;

        helper("(", 1, 0, comb, n);

        return comb;
    }

    void helper(std::string s, int open, int close, std::vector<std::string> &v, int n) {
        if (close == n) {
            v.push_back(s);
        }

        if (open < n) helper(s + "(", open + 1, close, v, n);
        if (close < open) helper(s + ")", open, close + 1, v, n);
    }
};