// LOWEST COMMON ANCESTOR IN A BINARY SEARCH TREE
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if((p->val < root->val) && (q->val < root->val)){
            return lowestCommonAncestor(root->left, p, q);
        }
        if((p->val > root->val) && (q->val > root->val)){
            return lowestCommonAncestor(root->right, p, q);
        }
        return root;
    }
};

// Generic Approach works for any Binary tree LCA find
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL || root == p || root == q) return root;

        TreeNode* lf = lowestCommonAncestor(root->left, p , q);
        TreeNode* rt = lowestCommonAncestor(root->right, p , q);

        if(lf == NULL) return rt;
        else if(rt == NULL) return lf;
        else return root;
    }
};
