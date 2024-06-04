#include <vector>
#include <queue>

class Solution {
public:
    bool canFinish(int numCourses, std::vector<std::vector<int>>& prerequisites) {
        // kahns alg

        std::vector<int> inCount(numCourses, 0);
        std::vector<std::vector<int>> adj(numCourses);

        for (int i = 0; i < prerequisites.size(); ++i) {
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
            inCount[prerequisites[i][1]]++;
        }

        std::queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (!inCount[i]) q.push(i);
        }

        int topoCount = 0;
        while (!q.empty()) {
            int top = q.front();
            topoCount++;

            for (int i = 0; i < adj[top].size(); ++i) {
                inCount[adj[top][i]]--;

                if (!inCount[adj[top][i]]) {
                    q.push(adj[top][i]);
                }
            }

            q.pop();
        }

        return topoCount == numCourses ? true : false;
    }
};