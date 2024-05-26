#include <cmath>
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
    bool isBalanced(TreeNode* root) {
        int height = 0;
        return dfs(root, height);
    }

    bool dfs(TreeNode* root, int& height) {
        if (!root) return true;

        int l = 0, r = 0;

        if (!dfs(root->left, l) || !dfs(root->right, r)) return false;
        if (std::abs(r - l) > 1) return false; 

        height = 1 + std::max(l, r);

        return true;
    }
};