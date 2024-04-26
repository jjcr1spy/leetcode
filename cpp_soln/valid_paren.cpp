#include <string>
#include <stack>

class Solution {
public:
    bool isValid(std::string s) {
        std::stack<char> stk;

        for (int i = 0; i < s.size(); ++i) {
            if (c == '(' || c == '[' || c == '{') {
               stk.push(c); 
               continue;
            } 

            if (stk.empty()) return false;

            if (c == ')' && stk.top() != c[m]) return false;
            else if (c == ']' && stk.top() != '[') return false;
            else if (c == '}' && stk.top() != '{') return false;

            stk.pop();
        }

        return stk.empty();
    }
};