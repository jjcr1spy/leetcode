#include <string>
#include <unordered_map>
#include <vector>
#include <set>
#include <algorithm>

class Solution {
public:
    std::vector<std::string> findItinerary(std::vector<std::vector<std::string>>& tickets) {
        // itinery is n + 1 location given n tickets
        std::unordered_map<std::string, std::multiset<std::string>> m; // multi set is ordered and allows for same strings in set
        std::vector<std::string> soln;

        for (int i = 0; i < tickets.size(); ++i) {
            m[tickets[i][0]].insert(tickets[i][1]);
        }

        dfs(m, soln, "JFK");

        std::reverse(soln.begin(), soln.end());

        return soln;
    }

    void dfs(std::unordered_map<std::string, std::multiset<std::string>>& m, std::vector<std::string>& soln, std::string loc) {
        while (!m[loc].empty()) {
            std::string s = *m[loc].begin();

            m[loc].erase(m[loc].begin());

            dfs(m, soln, s);
        }

        soln.push_back(loc);
    }
};