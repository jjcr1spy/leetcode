#include <vector>
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
    TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder) {
        int index = 0;
        return fillTree(index, 0, preorder.size() - 1, preorder, inorder);
    }

    TreeNode* fillTree (int& index, int left, int right, std::vector<int>& preorder, std::vector<int>& inorder) {
        if (left > right) return nullptr;

        TreeNode* node = new TreeNode(preorder[index]);

        int split;
        for (int i = 0; i < preorder.size(); i++) { // find inorder slice
            if (inorder[i] == preorder[index]) {
                split = i;
                break;
            }
        }
        index++;
        
        node->left = fillTree(index, left, split - 1, preorder, inorder);
        node->right = fillTree(index, split + 1, right, preorder, inorder);

        return node;
    }
};