#include <vector>
#include <utility>
#include <queue>
#include <cmath>

typedef std::priority_queue<std::pair<double, int>, std::vector<std::pair<double, int>>, std::greater<std::pair<double, int>>> PrioQ;

class Solution {
public:
    int minCostConnectPoints(std::vector<std::vector<int>>& points) {
        int numEdges = 0, nodeNum = 0, cost = 0, n = points.size();

        std::vector<int> visited(n, 0); 
        PrioQ pq;

        while (numEdges + 1 < n) {
            int nodeX = points[nodeNum][0], nodeY = points[nodeNum][1];
            
            for (int i = 0; i < n; ++i) {
                if (i == nodeNum || visited[i]) continue;

                int cost = std::abs(nodeY - points[i][1]) + std::abs(nodeX - points[i][0]);

                pq.push(std::make_pair(cost, i));
            }

            while (pq.top().second == nodeNum || visited[pq.top().second]) {
                pq.pop();
            }

            visited[nodeNum] = 1; 
            
            nodeNum = pq.top().second;
            cost += pq.top().first;

            numEdges++;
        }

        return cost; 
    }
};