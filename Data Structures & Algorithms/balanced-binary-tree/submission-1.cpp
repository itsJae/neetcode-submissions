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
    int getHeight(TreeNode* root) {
        if (root == NULL) return 0;

        int l = 1 + getHeight(root->left);
        int r = 1 + getHeight(root->right);

        return l > r ? l : r;
    }

    bool isBalanced(TreeNode* root) {
        if (root == NULL) return true;

        if (abs(getHeight(root->left) - getHeight(root->right)) > 1) {
            return false;
        }

        bool l = isBalanced(root->left);
        bool r = isBalanced(root->right);

        return l && r;
    }
};
