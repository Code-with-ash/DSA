class Solution {
    private:
    struct Info {
        int minnode;
        int maxnode;
        int maxsum;
    };
    int ans = 0;  
    Info calc(TreeNode* node) {
        if (node == NULL) return {INT_MAX, INT_MIN, 0};

        Info left  = calc(node->left);
        Info right = calc(node->right);

        if (left.maxnode < node->val && right.minnode > node->val) {
           int sum =  node->val + left.maxsum + right.maxsum;
           ans = max(ans , sum);
            return {
                min(left.minnode, node->val),
                max(right.maxnode, node->val),
                sum
            };
        }
        return {INT_MIN, INT_MAX, max(left.maxsum, right.maxsum)};
    }
public:
    int maxSumBST(TreeNode* root) {
        ans = 0;
     calc(root);
     return ans;
    }
};