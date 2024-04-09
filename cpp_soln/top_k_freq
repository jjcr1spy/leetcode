//#include <vector> for soln
//#include <unordered_map> for m
//#include <queue> for pq
//#include <utility> for pair

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> m;
        for (auto &i : nums) {
            m[i]++;
        }

        std::priority_queue<pair<int, int>> pq;

        for (auto &k : m) {
            pq.push(std::make_pair(k.second, k.first));
        }
        
        std::vector<int> soln;
        int s = nums.size();
        while (k && s) {
            soln.push_back(pq.top().second);
            pq.pop();

            k--;
            s--;
        }

        return soln;
    }
};