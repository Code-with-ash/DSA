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
    void f(TreeNode* node , int& ans , int prev){
        if(node == nullptr) return ;
        if(node->val >= prev) ans++;
        prev = max(prev , node->val);
        f(node->left , ans , prev) ;
        prev = max(prev , node->val);
        f(node->right , ans , prev) ;
    }
public:
    int goodNodes(TreeNode* root) {
        int ans = 0 ;
        int prev = root->val ;
        f(root , ans , prev);
        return ans ;
    }
};