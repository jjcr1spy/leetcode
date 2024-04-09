//#include <set>
//#include <vector>

class Solution {
public:
    int longestConsecutive(std::vector<int>& nums) {        
        if (nums.size() < 2) {
            return nums.size();
        }

        std::set<int> s(nums.begin(), nums.end());
        int curr_count = 1, max_count = 1, prev = *s.begin();
        std::set<int>::iterator itr = s.begin();

        while (++itr != s.end()) {
            int curr = *itr;

            if (prev + 1 == curr) {
                curr_count++;
            } else {
                if (curr_count > max_count) {
                    max_count = curr_count;
                }
                curr_count = 1;
            } 

            prev = curr;
        }

        if (curr_count > max_count) max_count = curr_count;

        return max_count;
    }
};