#include <algorithm>
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
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;

        dfs(root, diameter);

        return diameter;
    }

    int dfs(TreeNode * node, int& diameter) {
        if (!node) return 0;

        int l = dfs(node->left, diameter);
        int r = dfs(node->right, diameter);

        diameter = std::max(diameter, l + r); // in case longest path is between this node and "below"

        return 1 + std::max(l, r);
    }
};