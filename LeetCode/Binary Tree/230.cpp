// Kth SMALLEST ELEMENT IN BST
class Solution {
public:
    void solve(TreeNode* root, int &cnt, int &ans, int k){
        if(root == NULL)    return;
        //left, root, right 
        solve(root->left, cnt, ans, k);
        cnt++;
        if(cnt == k){
            ans = root->val;
            return;
        }
        solve(root->right, cnt, ans, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        
        int cnt = 0;        
        int ans;
        solve(root, cnt, ans, k);
        return ans;
    }
};

// USING MORRIS TRAVERSAL APPROACH
class Solution {
public:
    // Morris inorder traversal that returns sorted elements in a vector
    vector<int> morrisInorder(TreeNode* root) {
        vector<int> inorder;
        TreeNode* current = root;

        while (current != nullptr) {
            if (current->left == nullptr) {
                inorder.push_back(current->val);
                current = current->right;
            } else {
                TreeNode* pred = current->left;
                while (pred->right != nullptr && pred->right != current) {
                    pred = pred->right;
                }

                if (pred->right == nullptr) {
                    // Create a thread back to current
                    pred->right = current;
                    current = current->left;
                } else {
                    // Thread exists, remove it and visit current
                    pred->right = nullptr;
                    inorder.push_back(current->val);
                    current = current->right;
                }
            }
        }

        return inorder;
    }

    int kthSmallest(TreeNode* root, int k) {
        vector<int> inorder = morrisInorder(root);
        int N = (int)inorder.size();
        if (k > 0 && k <= N) {
            return inorder[k-1]; // N-k for Kth largest Element
        }
        return -1; 
    }
};

