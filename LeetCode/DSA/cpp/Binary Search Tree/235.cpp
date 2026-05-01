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
// Optimising the space complexity by using a while loop
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while (root) {
            if (p->val > root->val && q->val > root->val) {
                root = root->right;
            } 
            else if (p->val < root->val && q->val < root->val) {
                root = root->left;
            } 
            else {
                return root; // Found the split point
            }
        }
        return nullptr;
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
