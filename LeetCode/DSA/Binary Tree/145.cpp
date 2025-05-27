// POSTORDER TRAVERSAL
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        doPostorder(root, ans);
        return ans;
    }
private:
    void doPostorder(TreeNode *root, vector<int> &ans){
        if(root == nullptr) return;
        doPostorder(root->left, ans);
        doPostorder(root->right, ans); 
        ans.push_back(root->val); 
    }
};

// Morris Postorder Traversal
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        TreeNode dummy(0);
        dummy.left = root;
        TreeNode* curr = &dummy;

        while (curr) {
            if (curr->left == nullptr) {
                curr = curr->right;
            } else {
                TreeNode* pred = curr->left;
                while (pred->right && pred->right != curr) {
                    pred = pred->right;
                }

                if (pred->right == nullptr) {
                    pred->right = curr;
                    curr = curr->left;
                } else {
                    // Reverse the path and collect values
                    reverseAdd(curr->left, pred, result);
                    pred->right = nullptr;
                    curr = curr->right;
                }
            }
        }
        return result;
    }

private:
    void reverseAdd(TreeNode* from, TreeNode* to, vector<int>& result) {
        reversePath(from, to);
        TreeNode* node = to;
        while (true) {
            result.push_back(node->val);
            if (node == from) break;
            node = node->right;
        }
        reversePath(to, from);  // restore
    }

    void reversePath(TreeNode* from, TreeNode* to) {
        if (from == to) return;
        TreeNode *x = from, *y = from->right, *z;
        while (x != to) {
            z = y->right;
            y->right = x;
            x = y;
            y = z;
        }
    }
};
