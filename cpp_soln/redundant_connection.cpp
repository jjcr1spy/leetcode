#include <vector>

class Solution {
public:
    std::vector<int> findRedundantConnection(std::vector<std::vector<int>>& edges) {
        std::vector<int> parents, rank;

        for (int i = 0; i < edges.size(); ++i) {
            rank.push_back(1);
            parents.push_back(i);
        }

        for (int i = 0; i < edges.size(); ++i) {
            if (unionMerge(parents, rank, edges[i][0] - 1, edges[i][1] - 1)) {
                return std::vector<int> {edges[i][0], edges[i][1]};
            }
        }

        return std::vector<int>{};
    }

    int unionFind(std::vector<int>& parents, int i) {
        int find = i;

        while (find != parents[find]) {
            find = parents[find];
        }

        return find;
    }

    bool unionMerge(std::vector<int>& parents, std::vector<int>& rank, int i, int j) {
        int l = unionFind(parents, i);
        int r = unionFind(parents, j);

        if (l == r) return true;

        if (rank[l] > rank[r]) {
            rank[l] += rank[r];
            parents[r] = l;
        } else {
            rank[r] += rank[l];
            parents[l] = r;
        }

        return false;
    }
};