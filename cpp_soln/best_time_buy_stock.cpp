#include <algorithm>
#include <vector>

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {        
        int l = 0, r = 0, max = 0;

        while (r < prices.size()) {
            if (prices[r] < prices[l]) {
                l = r;
            }

            max = std::max(prices[r] - prices[l], max);

            r++;
        }

        return max;
    }
};