/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
private:
    void pushallin1(TreeNode* node, stack<TreeNode*>& st1) {
        while (node) {
            st1.push(node);
            node = node->left;
        }
    }
    void pushallin2(TreeNode* node, stack<TreeNode*>& st2) {
        while (node) {
            st2.push(node);
            node = node->right;
        }
    }
    int next(stack<TreeNode*>& st1){
        TreeNode* tmpnode = st1.top();
        st1.pop();
        pushallin1(tmpnode->right , st1);
        return tmpnode->val;
    }
    int before(stack<TreeNode*>& st2){
        TreeNode* tmpnode = st2.top();
        st2.pop();
        pushallin2(tmpnode->left , st2);
        return tmpnode->val;
    }

public:
    bool findTarget(TreeNode* root, int k) {
        stack<TreeNode*> st1;
        stack<TreeNode*> st2;
        pushallin1(root, st1);
        pushallin2(root, st2);
        int low = next(st1);
        int high = before(st2);
        while(low<high){
            if((low+high)==k) return true;
            if((low+high) > k){
               high = before(st2);
            }
            else if((low+high)< k) low = next(st1);
        }
        return false;
    }
};