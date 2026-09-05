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
    void f(TreeNode* node , TreeNode* edit){
        if(node == nullptr) return ;
        if(node->left){
            TreeNode* left = new TreeNode(node->left->val);
            edit->right = left ;
        }
        if(node->right){
            TreeNode* right = new TreeNode(node->right->val);
            edit->left = right ;
        }
        f(node->left , edit->right );
        f(node->right , edit->left );
    }
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root==nullptr) return root ;
        TreeNode* head = new TreeNode(root->val) ;
        f(root , head);
        return head ;
    }
};