#include <vector>
#include <queue>

class Solution {
public:
    int lastStoneWeight(std::vector<int>& stones) {
        std::priority_queue<int> pq(stones.begin(), stones.end());

        while (pq.size() > 1) {
            int m1 = pq.top();
            pq.pop();
            int m2 = pq.top();
            pq.pop();

            if (m1 != m2) pq.push(m1 - m2);
        }


        return pq.empty() ? 0 : pq.top();
    }
};