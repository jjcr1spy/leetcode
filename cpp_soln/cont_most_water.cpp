//#include <algorithm>
//#include <vector>

class Solution {
public:
    int maxArea(std::vector<int>& height) {
        int max = 0, i = 0, j = height.size() - 1;

        while (i < j) {
            int sum = std::min(height[i], height[j]) * (j - i);
            
            if (max < sum) max = sum;
            
            if (height[i] < height[j]) i++;
            else j--;
        }

        return max;
    }
};