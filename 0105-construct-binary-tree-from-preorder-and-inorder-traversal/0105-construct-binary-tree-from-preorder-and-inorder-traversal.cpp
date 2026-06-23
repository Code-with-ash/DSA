class Solution {
private:
    TreeNode* calc(vector<int>& preorder, vector<int>& inorder,
                   int pre_start, int pre_end,
                   int in_start, int in_end,
                   map<int, int>& mpp) {

        // Base case: invalid range
        if (pre_start > pre_end || in_start > in_end)
            return nullptr;

        TreeNode* root = new TreeNode(preorder[pre_start]);

        int inroot    = mpp[preorder[pre_start]];
        int NumsLeft  = inroot - in_start;   // Bug 1 fixed: was `instart`

        // Bug 2 & 3 fixed: correct argument order and index arithmetic
        TreeNode* left  = calc(preorder, inorder,
                               pre_start + 1, pre_start + NumsLeft,  // left subtree in preorder
                               in_start, inroot - 1,                 // left subtree in inorder
                               mpp);

        TreeNode* right = calc(preorder, inorder,
                               pre_start + NumsLeft + 1, pre_end,    // right subtree in preorder
                               inroot + 1, in_end,                   // right subtree in inorder
                               mpp);

        root->left  = left;
        root->right = right;
        return root;   // Bug 5 fixed: missing return
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int, int> mpp;
        for (int i = 0; i < (int)inorder.size(); i++)
            mpp[inorder[i]] = i;

        return calc(preorder, inorder,           // Bug 5 fixed: missing return
                    0, preorder.size() - 1,
                    0, inorder.size() - 1,
                    mpp);
    }
};