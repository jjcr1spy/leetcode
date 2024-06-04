#include <vector>
#include <algorithm>
#include <utility>
#include <climits>
#include <queue>

class Solution {
public:
    int networkDelayTime(std::vector<std::vector<int>>& times, int n, int k) {
        std::vector<std::vector<std::pair<int, int>>> adj(n + 1);  
        for (int i = 0; i < times.size(); ++i) {
            adj[times[i][0]].push_back({times[i][2], times[i][1]});
        }

        std::vector<int> kToNode(n + 1, INT_MAX);  
        kToNode[k] = 0;

        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
        pq.push({0, k});

        while (!pq.empty()) {
            std::pair<int, int> p = pq.top();
            pq.pop();

            if (p.first > kToNode[p.second]) continue;
            
            for (int i = 0; i < adj[p.second].size(); ++i) {\
                int dist = adj[p.second][i].first;
                int node = adj[p.second][i].second;

                if (kToNode[p.second] + dist < kToNode[node]) {
                    kToNode[node] = kToNode[p.second] + dist;

                    pq.push({kToNode[node], node});
                }
            }
        }

        int max = *std::max_element(kToNode.begin() + 1, kToNode.end());    

        return max == INT_MAX ? -1 : max;
    }
};