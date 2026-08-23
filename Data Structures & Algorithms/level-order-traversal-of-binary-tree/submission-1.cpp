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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == NULL) return ans;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int levelSize = q.size();
            vector<int> items;

            for (int i = 0; i < levelSize; ++i) {
                TreeNode* dq = q.front();
                q.pop();
                items.push_back(dq->val);
                
                if (dq->left != NULL) {
                    q.push(dq->left);
                }

                if (dq->right != NULL) {
                    q.push(dq->right);
                }
            }

            ans.push_back(items);
        }

        return ans;
    }
};
