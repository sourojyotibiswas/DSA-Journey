// CHECK SAME TREE
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // if(!p && !q) return true;
        // if (!p || !q) return false;
        // if (p->val == q->val) return false;
        if(p==NULL || q==NULL) return (p==q);

        return (p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);

    }
};