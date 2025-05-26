

// User function Template for C++

// Function to return the ceil of given number in BST.
int findCeil(Node* root, int input) {
    if (root == NULL)
        return -1;

    int c = -1;
    while (root != nullptr) {
        if (root->data == input) {
            return root->data; // exact match is the ceil
        } else if (root->data < input) {
            root = root->right; // ceil must be in right subtree
        } else {
            c = root->data; // potential ceil, go left to find smaller one
            root = root->left;
        }
    }
    return c; // return the smallest number >= input, or -1 if not found
}