#include <vector>
#include <queue>

class Solution {
public:
    int findKthLargest(std::vector<int>& nums, int k) {
        std::priority_queue<int> pq(nums.begin(), nums.end());

        while (--k) pq.pop();
        
        return pq.top();
    }
};