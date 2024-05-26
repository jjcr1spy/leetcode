#include <vector>
#include <queue>
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    std::vector<int> rightSideView(TreeNode* root) {
        if (!root) return {};

        std::vector<int> solution;
        std::queue<TreeNode *> q;

        q.push(root);

        while (!q.empty()) {
            int size = q.size();

            solution.push_back(q.front());

            for (int i = 0; i < size; i++) {
                TreeNode * top = q.front();
                q.pop();

                if (top->right) q.push(top->right);
                if (top->left) q.push(top->left);
            }
            
        }

        return solution;
    }
};