// return the Kth largest element in the given BST rooted at 'root'
class Solution {
public:
    // Morris inorder traversal that returns sorted elements in a vector
    vector<int> morrisInorder(Node* root) {
        vector<int> inorder;
        Node* current = root;

        while (current != nullptr) {
            if (current->left == nullptr) {
                inorder.push_back(current->data);
                current = current->right;
            } else {
                Node* pred = current->left;
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
                    inorder.push_back(current->data);
                    current = current->right;
                }
            }
        }

        return inorder;
    }

    int kthLargest(Node* root, int k) {
        vector<int> inorder = morrisInorder(root);
        int N = (int)inorder.size();
        if (k > 0 && k <= N) {
            return inorder[N-k];
        }
        return -1; 
    }
};