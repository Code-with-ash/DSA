class Solution {
private:
    void f(TreeNode* node, int k, int& counter, int& ans) {
        if (node == nullptr)
            return;

        f(node->left, k, counter, ans); // 1. visit left subtree first

        counter++; // 2. count current node
        if (counter == k) {
            ans = node->val;
            return; // optional: stop early once found
        }

        f(node->right, k, counter, ans); // 3. then visit right subtree
    }

public:
    int kthSmallest(TreeNode* root, int k) {
        int counter = 0;
        int ans = 0;
        f(root, k, counter, ans);
        return ans;
    }
};