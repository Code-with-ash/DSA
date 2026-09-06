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
    private:
    int f(TreeNode* node , int& ans){
        if(node == nullptr ) return 0 ;
        int lh = f(node->left , ans );
        int rh = f(node->right , ans );
        ans = max(lh+rh , ans);
        return 1+ max(lh, rh);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0 ;
        f(root , ans );
        return ans ;
    }
};