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
    private :
    TreeNode* calc(vector<int>& inorder, vector<int>& postorder , int poststart , int postend , int instart , int inend , map<int, int>& mp){
        if(poststart > postend || instart > inend) return nullptr ;

        TreeNode* root = new TreeNode(postorder[postend]);

        int inroot = mp[root->val];
        
        int NumsLeft = inroot - instart; // 1 number on left 

         TreeNode* left  = calc(inorder, postorder,
                               poststart, poststart + NumsLeft - 1,  // left in postorder
                               instart, inroot - 1,                   // left in inorder
                               mp);

        TreeNode* right = calc(inorder, postorder,
                               poststart + NumsLeft, postend - 1,    // right in postorder
                               inroot + 1, inend,                     // right in inorder
                               mp);

        
        root -> left = left;
        root-> right = right;

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map < int , int > mp;
        for(int i = 0 ; i < (int)inorder.size(); i++){
            mp[inorder[i]]= i;
        }
        return calc(inorder , postorder , 0 , postorder.size()-1 , 0 , inorder.size()-1 , mp);
    }
};