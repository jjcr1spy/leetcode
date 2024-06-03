#include <vector>

class Solution {
public:
    void solve(std::vector<std::vector<char>>& board) {
        int m = board.size(), n = board[0].size();

        for (int i = 0; i < m; ++i) { // leftmost and rightmost column
            dfs(board, i, 0);
            dfs(board, i, n - 1);
        }

        for (int i = 0; i < n; ++i) { // bottom and top row
            dfs(board, 0, i);
            dfs(board, m - 1, i);
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                else if (board[i][j] == 'E') board[i][j] = 'O';
            }
        }
    }

    void dfs(std::vector<std::vector<char>>& board, int i, int j) {
        if (i < 0 || j < 0 || i >= board.size() || j >= board[i].size() || board[i][j] != 'O') return;

        board[i][j] = 'E';

        dfs(board, i + 1, j);
        dfs(board, i - 1, j);
        dfs(board, i, j + 1);
        dfs(board, i, j - 1);
    }
};