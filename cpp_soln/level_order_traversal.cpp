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
    std::vector<std::vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};

        std::vector<std::vector<int>> v;
        std::queue<TreeNode *> q;

        q.push(root);

        while (!q.empty()) {
            std::vector<int> innerV;
            int size = q.size();

            for (int i = 0; i < size; i++) {
                TreeNode * front = q.front();
                q.pop();

                innerV.push_back(front->val);

                if (front->left) q.push(front->left);
                if (front->right) q.push(front->right);
            }

            v.push_back(innerV);
        }
        
        return v;
    }
};