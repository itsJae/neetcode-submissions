class Solution {
public:
    TreeNode* doBuild(vector<int>& preorder, vector<int>& inorder,
                       unordered_map<int,int>& m,
                       int preStart, int preEnd,
                       int inStart, int inEnd) {
        // base case: 구간이 비었으면 (원소 개수 = end - start + 1 <= 0)
        if (preStart > preEnd || inStart > inEnd) return nullptr;

        int rootVal = preorder[preStart];      // 이 구간에서 preorder의 첫 원소가 루트
        TreeNode* root = new TreeNode(rootVal);

        int mid = m[rootVal];                  // inorder 전체(원본) 기준 절대 위치
        int leftSize = mid - inStart;          // 왼쪽 서브트리의 원소 개수

        root->left = doBuild(preorder, inorder, m,
                              preStart + 1, preStart + leftSize,
                              inStart, mid - 1);

        root->right = doBuild(preorder, inorder, m,
                               preStart + leftSize + 1, preEnd,
                               mid + 1, inEnd);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> m;
        for (int i = 0; i < inorder.size(); ++i)
            m[inorder[i]] = i;

        return doBuild(preorder, inorder, m, 0, preorder.size()-1, 0, inorder.size()-1);
    }
};