#include <vector>
#include <utility>
#include <queue>
#include <climits>

class Solution {
public:
    int findCheapestPrice(int n, std::vector<std::vector<int>>& flights, int src, int dst, int k) {
        std::vector<std::vector<std::pair<int, int>>> adj(n);

        for (int i = 0; i < flights.size(); ++i) {
            adj[flights[i][0]].push_back({flights[i][1], flights[i][2]});
        }

        std::vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        std::queue<std::pair<int, int>> q;
        q.push({src, dist[src]});

        int waves = 0;

        while (waves <= k && !q.empty()) {
            int size = q.size();

            for (int i = 0; i < size; ++i) {
                int node = q.front().first, weight = q.front().second;

                for (int j = 0; j < adj[node].size(); ++j) {
                    int newDist = adj[node][j].second + weight, neighbor = adj[node][j].first;
                    if (newDist < dist[neighbor]) {
                        dist[neighbor] = newDist;
                        q.push({neighbor, newDist});
                    }
                }

                q.pop();
            }

            ++waves;
        }

        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};