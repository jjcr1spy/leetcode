#include <string>
#include <vector>
#include <stack>
#include <ctype.h>

class Solution {
public:
    int evalRPN(std::vector<std::string>& tokens) {
        std::stack<int> stk;
        int x, y;

        for (int i = 0; i < tokens.size(); ++i) {
            std::string token = tokens[i];
            
            if (token.size() > 1 || isdigit(token[0])) {
                stk.push(stoi(token));
                continue;
            }

            x = stk.top();
            stk.pop();
            y = stk.top();
            stk.pop();

            if (tokens[i][0] == '+') stk.push(y + x);
            else if (tokens[i][0] == '*') stk.push(y * x);
            else if (tokens[i][0] == '/') stk.push(y / x);
            else if (tokens[i][0] == '-') stk.push(y - x);
        }

        return stk.top();
    }
};


