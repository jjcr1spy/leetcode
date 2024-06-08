#include <vector>

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        if (prices.size() == 1) return 0;

        // 3 states in DFS machine
        // a is hold (a -> a) or buy (a -> b)
        // b is hold (b -> b) or sell (b -> c)
        // c is cooldown (c -> a)

        int a = 0, b = -prices[0], c = 0; 
        for (int i = 1; i < prices.size(); ++i) {
            int newA = std::max(a, c);
            int newB = std::max(b, a - prices[i]); // buying said price or holding what you have
            int newC = std::max(c, b + prices[i]); // selling and updates or just keep same c

           a = newA, b = newB, c = newC;
        }

        return c; 
    }
};