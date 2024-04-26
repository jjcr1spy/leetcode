#include <vector>
#include <deque>

class Solution {
public:
    std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k) {        
        if (nums.size() == 1) return {nums[0]};
        
        std::vector<int> v;
        std::deque<int> q;

        int i = 0, j = 0;
        while (j < nums.size()) {

            while (!q.empty() && nums[j] >= nums[q.back()]) q.pop_back();
                
            q.push_back(j);

            if (q.front() < i) {
                q.pop_front();
            }

            if (j - i + 1 == k) {
                v.push_back(nums[q.front()]);
                i++;     
            }

            j++;
        }

        return v;
    }
};