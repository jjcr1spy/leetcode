#include <vector>
#include <string>

class Solution {
public:
    bool exist(std::vector<std::vector<char>>& board, std::string word) {
        bool solution = false;

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == word[0]) {
                    if (dfs(board, word, i, j, 0)) return true;
                }
            }
        }

        return false;
    }

    bool dfs(std::vector<std::vector<char>>& board, const std::string& word, int i, int j, int pos) {
        if (i >= board.size() || i < 0 || j >= board[0].size() || j < 0 || board[i][j] != word[pos]) return false;    
        if (pos == word.length() - 1) return true;

        char c = board[i][j];
        board[i][j] = '#';

        if (dfs(board, word, i + 1, j, pos + 1) || dfs(board, word, i - 1, j, pos + 1) || dfs(board, word, i, j + 1, pos + 1) || dfs(board, word, i, j - 1, pos + 1)) {
            return true;
        }

        board[i][j] = c;

        return false;
    }
};