//#include <vector>
//#include <unordered_map>
//#include <string>
//#include <algorithm>

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<string, vector<string>> m;

        for (int i = 0; i < strs.size(); i++) {
            string sorted_str = strs[i];

            sort(sorted_str.begin(), sorted_str.end());

            m[sorted_str].push_back(strs[i]);
        }

        vector<vector<string>> v;
        for (const auto & [ key, value ] : m) {
            v.push_back(value);                   
        }

        return v;
    }
};