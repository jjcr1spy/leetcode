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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root) return false;
        
        if (isSameTree(root, subRoot)) return true;

        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot); 
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true; // both null
        if ((!p && q) || (!q && p)) return false; // one null other isnt
        if (p->val != q->val) return false; // values dont match
        
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};