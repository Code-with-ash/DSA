/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
    private:
    TreeNode* f(TreeNode* node , TreeNode* p , TreeNode* q){
        if(node == nullptr ) return nullptr ;
        if(node->val == p->val ) return node ;
        if(node->val == q->val ) return node ;
        TreeNode* left = f(node->left , p , q );
        TreeNode* right = f(node->right , p , q );
        if(left && right ) return node ;
        else if(left) return left ;
        else if(right)  return right ;
        else return nullptr ;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root->val == p->val || root->val == q->val ) return root ;
        return f(root , p , q );
    }
};