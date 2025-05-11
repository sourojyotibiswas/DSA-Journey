// PREORDER TRAVERSAL
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        doPreorder(root, ans);
        return ans;
    }
private:
    void doPreorder(TreeNode *root, vector<int> &ans){
        if(root == nullptr) return;
        ans.push_back(root->val);
        doPreorder(root->left, ans);
        doPreorder(root->right, ans);  
    }
};

// Morris Preorder Traversal
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
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
                    inorder.push_back(curr->val);
                    curr = curr->left;
                }
                else{
                    prev->right = nullptr;
                    curr=curr->right;
                }
            }
        }
        return inorder;
    }
};