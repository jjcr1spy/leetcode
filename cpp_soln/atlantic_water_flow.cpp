#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> turn{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    std::vector<std::vector<int>> pacificAtlantic(std::vector<std::vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        std::vector<std::vector<int>> pacific(m, std::vector<int>(n, 0)), atlantic(m, std::vector<int>(n, 0)), solution;

        for (int i = 0; i < m; i++) { // who can reach left pacific border or right atlantic border 
            dfs(heights, pacific, i, 0);
            dfs(heights, atlantic, i, n - 1);
        }

        for (int i = 0; i < n; i++) { // who can reach upper pacific border or bottom atlantic border 
            dfs(heights, pacific, 0, i);
            dfs(heights, atlantic, m - 1, i);
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (pacific[i][j] && atlantic[i][j]) solution.push_back({i, j});
            }
        }

        return solution;
    }

    void dfs(std::vector<std::vector<int>>& heights, std::vector<std::vector<int>>& visited, int x, int y) {        
        visited[x][y] = 1;

        for (int i = 0; i < 4; i++)  {
            int newx = turn[i][0] + x, newy = turn[i][1] + y;
            
            if (newx < 0 || newy < 0 || newx >= heights.size() || newy >= heights[0].size() || visited[newx][newy]) continue; // out of bounds or visited already
            if (heights[newx][newy] >= heights[x][y]) dfs(heights, visited, newx, newy);
        }
    }
};