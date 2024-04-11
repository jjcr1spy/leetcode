//#include <vector>
//#include <algorithm>

class Solution {
public:
    std::vector<vector<int>> threeSum(std::vector<int>& nums) {
        if (nums.size() < 3) return {}; // optimize
        
        std::sort(nums.begin(), nums.end());

        if (nums[0] > 0) return {}; // optimize

        std::vector<std::vector<int>> soln;

        int j, k, sum, last_j_val = -1, last_k_val = -1;
        for (int i = 0; i < nums.size() - 2; i++) {
            if (nums[i] > 0) break; // optimize

            if (i > 0 && nums[i - 1] == nums[i]) { // no duplicate i values
                continue;
            }
            
            j = i + 1;
            k = nums.size() - 1;

            while (j < k) {
                sum = nums[i] + nums[j] + nums[k];

                if (sum == 0) {
                    soln.push_back({nums[i], nums[j], nums[k]});

                    while (j < k && nums[j] == nums[j + 1]) { // no duplicate j values
                        j++;
                    }
                    j++;
                    
                    while (j < k && nums[k] == nums[k - 1]) { // no duplicate k values
                        k--; 
                    }
                    k--;
                } else if (sum < 0) {
                    j++;
                } else {
                    k--; 
                }
            }   
        }

        return soln;
    }
};