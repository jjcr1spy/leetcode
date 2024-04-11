#include <vector>

class Solution {
public:
    bool isValidSudoku(std::vector<std::vector<char>>& board) {
        int sub[9][9] = {0};
        int row[9][9] = {0};
        int col[9][9] = {0};

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;

                int index = board[i][j] - '0' - 1; // use -1 bc we want to index at 8 w 9 for ex
                int area = (j / 3) * 3 + (i / 3);

                if (sub[area][index] == 1 || row[i][index] || col[j][index]) return false;
                else sub[area][index] = 1; row[i][index] = 1; col[j][index] = 1;
            }
        }

        return true;
    }
};