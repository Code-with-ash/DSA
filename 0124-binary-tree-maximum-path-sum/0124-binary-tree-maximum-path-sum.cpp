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
    int calculate(TreeNode* node , int& maxsum){
        if(node==NULL) return 0;
        int lh = max(0,calculate(node->left , maxsum));
        int rh = max(0,calculate(node->right , maxsum));
        maxsum = max(maxsum ,lh+rh+node->val);
        return  node->val + max(lh,rh);
    }
public:
    int maxPathSum(TreeNode* root) {
        int maxsum = INT_MIN;
        calculate(root , maxsum);
        return maxsum;
    }
};