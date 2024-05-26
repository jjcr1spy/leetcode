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
    int maxPathSum(TreeNode* root) {
        int max = -1001;
        
        dfs(root, max);

        return max;
    }

    int dfs(TreeNode* root, int& max) {
        if (!root) return 0;

        int l = std::max(dfs(root->left, max), 0); // will be 0 if cant "contribute" to global max
        int r = std::max(dfs(root->right, max), 0); // ^^

        max = std::max(l + r + root->val, max); // see if our path is the best

        return root->val + std::max(l, r);
    }
};