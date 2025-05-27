// INORDER TRAVERSAL
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        doInorder(root, ans);
        return ans;
    }
private:
    void doInorder(TreeNode *root, vector<int> &ans){
        if(root == nullptr) return;
        doInorder(root->left, ans);
        ans.push_back(root->val);
        doInorder(root->right, ans);  
    }
};

// Morris Traversal
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
        TreeNode *curr = root;

        while(curr != nullptr){
            if(curr->left == nullptr){
                inorder.push_back(curr->val);
                curr = curr->right;
            }
            else{
                TreeNode *prev = curr->left;
                while(prev->right && prev->right != curr){
                    prev = prev->right;
                }
                if(prev->right == nullptr){
                    prev->right = curr;
                    curr = curr->left;
                }
                else{
                    prev->right = nullptr;
                    inorder.push_back(curr->val);
                    curr=curr->right;
                }
            }
        }
        return inorder;
    }
};