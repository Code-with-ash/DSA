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
    TreeNode* findlastright(TreeNode* node){
        while(node->right){
            node = node->right;
        }
        return node;
    }
    TreeNode* mergenodes(TreeNode* curr){
        if(curr->left == NULL) return curr -> right;
        else if(curr->right == NULL) return curr->left;
        TreeNode* rightchild = curr -> right;
        TreeNode* lastright = findlastright(curr->left);
        lastright->right = rightchild;
        return curr->left;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return nullptr;
        if(root->val == key) return mergenodes(root);
        TreeNode* dummy = root;
        while(root){
            if(root->val>key){
                // its on left
                if(root->left!=NULL && root->left->val == key){
                    // left key is val;
                    root->left = mergenodes(root->left);
                    break;
                }
                else {
                    root = root -> left;
                }
            }
            else{
                //either root is key or its on right side
                if(root->right !=NULL && root->right->val == key){
                    root -> right = mergenodes(root->right);
                    break;
                }
                else{
                    root = root -> right;
                }
            }
        }
        return dummy;
    }
};