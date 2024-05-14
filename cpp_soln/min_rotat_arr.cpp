#include <vector>
#include <algorithm>

class Solution {
public:
    int findMin(std::vector<int>& nums) {
        int min = nums[0], i = 0, j = nums.size() - 1;

        while (i <= j) {
            if (nums[i] < nums[j]) {
                min = std::min(min, nums[i]);
                break;
            }

            int mid = i + (j - i) / 2;
            min = std::min(min, nums[mid]);

            if (nums[mid] <= nums[j]) j = mid - 1;
            else i = mid + 1;
        }

        return min;
    }
};