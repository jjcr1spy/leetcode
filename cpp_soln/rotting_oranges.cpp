#include <vector>
#include <queue>
#include <utility>

class Solution {
public:
    std::vector<std::vector<int>> move{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    int orangesRotting(std::vector<std::vector<int>>& grid) {
        std::queue<std::pair<int, int>> q;

        int freshCount = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 2) q.push({i, j});
                else if (grid[i][j] == 1) freshCount++;
            }
        }

        q.push({-1, -1}); // indicate a "minute" has passed
        int time = -1;

        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            
            q.pop();

            if (x == -1) {
                time++;

                if (!q.empty()) q.push({-1, -1}); // indicate another "wave" has passed
            } else {
                for (int i = 0; i < 4; ++i) {
                    int newx = x + move[i][0];
                    int newy = y + move[i][1];

                    if (newx >= grid.size() || newx < 0 || newy >= grid[0].size() || newy < 0 || grid[newx][newy] != 1) {
                        continue;
                    }

                    freshCount--;
                    grid[newx][newy] = 2;
                    q.push({newx, newy});
                }
            }
        }

        if (!freshCount) return time;

        return -1;
    }
};