#include <vector>

class Solution {
public:
    int search(std::vector<int>& nums, int target) {
        int low = 0, mid, high = nums.size() - 1;
        
        while (low <= high) {
            mid = low + (high - low) / 2;
            if (nums[mid] < target) low = mid + 1;
            else if (nums[mid] > target) high = mid - 1;
            else return mid;
        }
        
        return -1;
    }
};