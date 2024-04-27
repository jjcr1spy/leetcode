#include <vector>
#include <stack>
#include <utility>
#include <algorithm>

class Solution {
public:
    int largestRectangleArea(std::vector<int>& heights) {
        std::stack<std::pair<int, int>> stk;
        int max = 0, start, l = heights.size();

        for (int i = 0; i < l; i++) {
            start = i; 

            while (!stk.empty() && stk.top().second > heights[i]) {
                int index = stk.top().first;
                int height = stk.top().second;
                
                stk.pop();

                max = std::max(max, (i - index) * height);

                start = index;
            }

            stk.push({start, heights[i]});
        }

        while (!stk.empty()) {
            int index = stk.top().first;
            int height = stk.top().second;
            
            stk.pop();

            max = std::max(max, (l - index) * height);
        }

        return max;
    }
};