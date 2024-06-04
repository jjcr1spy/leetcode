#include <vector>
#include <algorithm>
#include <queue>
#include <climits>

class Solution {
public:
    std::vector<std::vector<int>> dir{{-1, 0}, {1, 0}, {0, -1}, {0 , 1}};

    int swimInWater(std::vector<std::vector<int>>& grid) {
        std::vector<std::vector<int>> dist(grid.size(), std::vector<int>(grid[0].size(), INT_MAX));
        std::priority_queue<std::vector<int>, std::vector<std::vector<int>>, std::greater<std::vector<int>>> pq;

        dist[0][0] = grid[0][0];
        pq.push({grid[0][0], 0, 0});

        while (!pq.empty()) {
            int height = pq.top()[0], i = pq.top()[1], j = pq.top()[2];
            pq.pop();

            for (int k = 0; k < 4; ++k) {
                int x = dir[k][0] + i;
                int y = dir[k][1] + j; 

                if (x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size()) continue;

                int new_height = std::max(height, grid[x][y]);
                if (new_height < dist[x][y]) {
                    dist[x][y] = new_height;
                    pq.push({new_height, x, y});
                }
            }
        }

        return dist[grid.size() - 1][grid[0].size() - 1];
    }
};
