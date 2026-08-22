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
    int findDiameter(TreeNode* root) {
        if (root == NULL) return 0;

        int l = 1 + findDiameter(root->left);
        int r = 1 + findDiameter(root->right);
    
        return l > r ? l : r;
    }

    void doDiameter(TreeNode* root, int *max) {
        if (root == NULL) return;

        int leftD = findDiameter(root->left);
        int rightD = findDiameter(root->right);

        if (leftD + rightD > *max) {
            *max = leftD + rightD;
        }

        doDiameter(root->left, max);
        doDiameter(root->right, max);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int max = 0;
        doDiameter(root, &max);
        return max;
    }
};
