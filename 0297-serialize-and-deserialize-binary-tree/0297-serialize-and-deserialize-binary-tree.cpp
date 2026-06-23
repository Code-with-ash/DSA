/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
 string serialize(TreeNode* root) {
    if (root == nullptr) return ""; 
    queue<TreeNode*> q;
    q.push(root);
    string s;
    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        if (node == nullptr) { s += "# "; continue; }  // space after each token
        s += to_string(node->val) + " ";
        q.push(node->left);
        q.push(node->right);
    }
    return s;
}
TreeNode* deserialize(string data) {
    if (data.empty()) return nullptr;
    istringstream ss(data);
    string str;

    if (!(ss >> str) || str == "#") return nullptr;  // str now holds root val
    // ss >> str;   ← DELETE THIS LINE
    TreeNode* root = new TreeNode(stoi(str));         // correctly uses root val
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();

        ss >> str;
        if (str != "#") {
            node->left = new TreeNode(stoi(str));
            q.push(node->left);
        }

        ss >> str;
        if (str != "#") {
            node->right = new TreeNode(stoi(str));
            q.push(node->right);
        }
    }
    return root;
}
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));