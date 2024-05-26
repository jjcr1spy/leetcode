#include <string>
#include <sstream>
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    std::string serialize(TreeNode* root) {        
        std::stringstream ss {};

        dfs(root, ss);

        return ss.str();
    }

    void dfs(TreeNode* root, std::stringstream& ss) {
        if (!root) {
            ss << "N ";
            return;
        }
        
        ss << std::to_string(root->val) << ' ';

        dfs(root->left, ss);
        dfs(root->right, ss);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(std::string data) {
        std::stringstream ss {data};
        
        return helper(ss);
    }

    TreeNode* helper(std::stringstream& ss) {
        std::string s;
        ss >> s;

        if (s == "N") return nullptr;
        
        TreeNode * node = new TreeNode(stoi(s));

        node->left = helper(ss);
        node->right = helper(ss);

        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));