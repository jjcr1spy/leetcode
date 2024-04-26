#include <vector>
#include <stack>

class Solution {
public:
    std::vector<int> dailyTemperatures(std::vector<int>& temperatures) {
        std::vector<int> soln(temperatures.size());
        std::stack<int> stk;

        int i = temperatures.size() - 1;
        while (i >= 0) {
            while (!stk.empty() && temperatures[i] >= temperatures[stk.top()]) stk.pop();

            if (stk.empty()) soln[i] = 0; 
            else soln[i] = stk.top() - i;

            stk.push(i--);
        }

        return soln;
    }
};