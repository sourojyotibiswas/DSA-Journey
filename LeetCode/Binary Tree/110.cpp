// CHECK BALANCED BINARY TREE

// Naive Approach: TC=O(N^2)
class Solution {
public:
    int height(TreeNode* root) {
        int ans=0;
        if(!root) return 0;
        else{
            ans = 1+max(height(root->left), height(root->right));
        }
        return ans;
    }
    bool isBalanced(TreeNode* root) {
        if(root == nullptr) return true;

        int lh = height(root->left);
        int rh = height(root->right);

        if(abs(rh-lh)>1) return false;

        bool left = isBalanced(root->left);
        bool right = isBalanced(root->right);

        if(!left || !right) return false;

        return true;
    }
};

// TC=O(N), SC=O(N)
class Solution {
public:
    // Helper function returns height if balanced, -1 if not
    int checkHeight(TreeNode* root) {
        if (!root) return 0;

        int leftHeight = checkHeight(root->left);
        if (leftHeight == -1) return -1;

        int rightHeight = checkHeight(root->right);
        if (rightHeight == -1) return -1;

        if (abs(leftHeight - rightHeight) > 1) return -1;

        return 1 + max(leftHeight, rightHeight);
    }

    bool isBalanced(TreeNode* root) {
        return checkHeight(root) != -1;
    }
};