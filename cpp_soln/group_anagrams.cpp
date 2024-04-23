#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
        std::unordered_map<std::string, std::vector<std::string>> m;

        for (int i = 0; i < strs.size(); i++) {
            std::string sorted_str = strs[i];

            std::sort(sorted_str.begin(), sorted_str.end());

            m[sorted_str].push_back(strs[i]);
        }

        std::vector<std::vector<std::string>> v;
        for (const auto & [ key, value ] : m) {
            v.push_back(value);                   
        }

        return v;
    }
};