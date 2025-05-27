// SYMMETRIC TREE OR MIRROR IMAGE
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return root == nullptr || help(root->left, root->right);
    }
    bool help(TreeNode* left, TreeNode* right){
        if(left == nullptr || right == nullptr) return left==right;
        if(left->val != right->val) return false;

        return help(left->left, right->right) && help(left->right, right->left);
    }
};