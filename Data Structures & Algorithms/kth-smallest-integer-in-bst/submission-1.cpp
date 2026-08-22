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
    void doSmallest(TreeNode* root, vector<int>& inOrder) {
        if (root == NULL) return;

        doSmallest(root->left, inOrder); 
        inOrder.push_back(root->val);
        doSmallest(root->right, inOrder); 
    }

    int kthSmallest(TreeNode* root, int k) {
        if (root == NULL) return 0;

        vector<int> inOrder;
        doSmallest(root, inOrder);

        return inOrder[k - 1];
    }
};
