class Solution {
    bool same(TreeNode* root, TreeNode* subroot){
        if(root == nullptr && subroot == nullptr) return true;
        if(root == nullptr || subroot == nullptr) return false;

        if(root->val != subroot->val) return false;

        return same(root->left, subroot->left) &&
               same(root->right, subroot->right);
    }

public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {

        if(root == nullptr) return false;

        if(same(root, subRoot))
            return true;

        return isSubtree(root->left, subRoot) ||
               isSubtree(root->right, subRoot);
    }
};