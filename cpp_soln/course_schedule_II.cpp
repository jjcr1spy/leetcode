#include <vector>
#include <queue>

class Solution {
public:
    std::vector<int> findOrder(int numCourses, std::vector<std::vector<int>>& prerequisites) {
        std::vector<int> inCount(numCourses, 0), soln;
        std::vector<std::vector<int>> adj(numCourses);

        for (int i = 0; i < prerequisites.size(); ++i) {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            inCount[prerequisites[i][0]]++;
        }

        std::queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (!inCount[i]) q.push(i);
        }

        while (!q.empty()) {
            int top = q.front();
            soln.push_back(top);

            for (int i = 0; i < adj[top].size(); ++i) {
                inCount[adj[top][i]]--;

                if (!inCount[adj[top][i]]) {
                    q.push(adj[top][i]);
                }
            }

            q.pop();
        }

        return (soln.size() == numCourses) ? soln : std::vector<int>{};
    }
};