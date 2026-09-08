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
    bool f(TreeNode* node , long long low, long long high){
        if(node == nullptr) return true ;
        if(node->val <= low || node->val >= high) return false ;
        bool left = f(node->left , low , node->val);
        bool right=f(node->right , node->val , high);
        return left && right ;
    }
public:
    bool isValidBST(TreeNode* root) {
        return f(root , LLONG_MIN, LLONG_MAX);
    }
};