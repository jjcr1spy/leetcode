#include <vector>

class Solution {
public:
    bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
        int low_row = 0, mid, high = matrix.size() - 1;
        
        while (low_row < high) {
            mid = low_row + (high - low_row) / 2;

            if (matrix[mid][0] == target) {
                return true;
            }

            if (matrix[mid][0] < target && matrix[mid + 1][0] > target) {
                low_row = mid;
                break;
            } else if (matrix[mid][0] > target) {
                high = mid - 1;
            } else {
                low_row = mid + 1;  
            }
        }
        
        int low_col = 0;
        high = matrix[0].size() - 1;
        
        while (low_col <= high) {
            mid = low_col + (high - low_col) / 2;

            if (matrix[low_row][mid] < target) low_col = mid + 1;
            else if (matrix[low_row][mid] > target) high = mid - 1;
            else return true;
        }

        return false;
    }
};