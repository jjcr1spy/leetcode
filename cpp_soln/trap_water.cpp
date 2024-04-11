#include <vector>
#include <algorithm>

class Solution {
public:
    int trap(std::vector<int>& height) {
        int s = height.size();

        std::vector<int> left(s, 0), right(s, 0);

        int max = height[0];
        for (int i = 1; i < s; i++) {
            left[i] = max;

            if (max < height[i]) {
                max = height[i];
            }          
        }

        max = height[s - 1];
        for (int i = s - 1; i >= 0; i--) {
            right[i] = max;

            if (max < height[i]) {
                max = height[i];
            }          
        }

        int water = 0, to_add;
        for (int i = 1; i < s - 1; i++) {
            to_add = std::min(left[i], right[i]) - height[i];

            if (to_add > 0) water += to_add;
        }

        return water;
    }
};