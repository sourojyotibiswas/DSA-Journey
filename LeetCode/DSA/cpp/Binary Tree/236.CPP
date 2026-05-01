// LOWEST COMMON ANCESTOR OF BINARY TREE
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //base case
        if(root == NULL || root == p || root == q) return root;

        TreeNode* lt = lowestCommonAncestor(root->left, p, q);
        TreeNode* rt = lowestCommonAncestor(root->right, p, q);

        if(lt == NULL) return rt;
        else if(rt == NULL) return lt;
        else return root;
    }
};