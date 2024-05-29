#include <vector>
#include <queue>
#include <utility>
#include <cmath>

class Solution {
public:
    std::vector<std::vector<int>> kClosest(std::vector<std::vector<int>>& points, int k) {
        std::priority_queue<std::pair<double, int>, std::vector<std::pair<double, int>>, std::greater<std::pair<double, int>>> pq;

        for (int i = 0; i < points.size(); i++) {
            float distance = std::sqrt(points[i][0] * points[i][0] + points[i][1] * points[i][1]);

            pq.push(std::make_pair(distance, i));
        }

        std::vector<std::vector<int>> soln(k);
        int i = 0;

        while (i < k) {
            int index = pq.top().second;
            soln[i++] = points[index];
            pq.pop();
        }

        return soln;
    }
};