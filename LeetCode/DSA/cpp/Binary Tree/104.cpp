// MAX. DEPTH OF BINARY TREE
class Solution {
public:
    int maxDepth(TreeNode* root) {
        int ans=0;
        if(!root) return 0;
        else{
            ans = 1+max(maxDepth(root->left), maxDepth(root->right));
        }
        return ans;
    }
};