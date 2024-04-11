#include <vector>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& numbers, int target) {
        int i = 0, j = numbers.size() - 1, val;
        
        while (i < j) {
            val = numbers[j] + numbers[i];

            if (val == target) return {i + 1, j + 1};
            else if (val < target) i++; 
            else j--;           
        }

        return {};
    }
};