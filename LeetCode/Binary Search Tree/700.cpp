class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root == nullptr || root->val == val) {
            return root; // found the node or reached the end without finding
        }
        
        if (val < root->val) {
            return searchBST(root->left, val); // search left subtree
        } else {
            return searchBST(root->right, val); // search right subtree
        }
    }
};