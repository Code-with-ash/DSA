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
    void calc(TreeNode* node , TreeNode*& prev){
        if(node == NULL) return;
        if(node->right) calc(node->right , prev);
        if(node->left) calc(node->left , prev);

        node->right = prev;
        node->left = nullptr;
        prev = node;
    }
public:
    void flatten(TreeNode* root) {
        // right left root 
        TreeNode* prev = nullptr;
        calc(root , prev);
    }
};