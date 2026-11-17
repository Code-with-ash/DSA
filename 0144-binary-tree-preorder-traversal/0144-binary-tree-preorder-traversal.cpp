class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        preorder(root, ans);
        return ans;
    }

private:
    void preorder(TreeNode* node, vector<int>& ans) {
        if (node == NULL) return;
        ans.push_back(node->val);
        preorder(node->left, ans);
        preorder(node->right, ans);
    }
};