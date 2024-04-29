#include <vector>
#include <algorithm>

class Solution {
public:
    int minEatingSpeed(std::vector<int>& piles, int h) {
        int low = 1, high = 0, mid, ans;

        for (int i = 0; i < piles.size(); i++) high = std::max(high, piles[i]);

        while (low <= high) {
            mid = low + (high - low) / 2;

            if (check(piles, mid, h)) {
                high = mid - 1;
                ans = mid;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }

    bool check(std::vector<int>& p, int mid, int h) {
        int count = 0;

        for (int i = 0; i < p.size(); i++) {
            if (p[i] < mid) { // p[i] less than k so in one go
                count++;
            } else if (p[i] % mid != 0) { // p[i] / k attemps plus one for remainder
                count += p[i] / mid + 1;
            } else { 
                count += p[i] / mid; 
            }

            if (count > h) return false;
        }

        return true;
    }
};