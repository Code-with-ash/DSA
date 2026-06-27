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
    void inorder(TreeNode* node ,TreeNode*& prev  , TreeNode*& first , TreeNode*& middle , TreeNode*& last){
        if(node== NULL) return;
        inorder(node->left , prev , first , middle , last);
        if(prev!= NULL && prev->val > node->val){
            if(first==NULL) {
                first = prev;
                middle = node;
            }
            else {
                last = node;
            }
        }
        prev = node;
        inorder(node->right , prev , first , middle , last);
    }
public:
    void recoverTree(TreeNode* root) {
        TreeNode* first = NULL;
        TreeNode* middle = NULL; 
        TreeNode* last = NULL ;
       TreeNode* prev = new TreeNode(INT_MIN);
        inorder(root , prev , first , middle , last);
        if(first && last) swap(first->val , last->val);
        else if(first && middle) swap(first->val , middle->val);
    }
};