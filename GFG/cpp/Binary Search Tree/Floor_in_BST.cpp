

// User function Template for C++

// Function to return the floor of given number in BST.
int floor(Node* root, int key) {
    if (root == NULL)
        return -1;

    int c = -1;
    while (root != nullptr) {
        if (root->data == key) {
            return root->data; 
        } else if (root->data < key) {
            c = root->data;    
            root = root->right;
        } else {
            root = root->left;
        }
    }
    return c;
}