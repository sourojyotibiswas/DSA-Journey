class Solution {
  public:
    // returns the inorder successor of the Node x in BST (rooted at 'root')
    int inOrderSuccessor(Node *root, Node *x) {
        // Your code here
        int succ = -1; // store the ans node
        
        while(root != NULL){
            if(x->data >= root->data) root = root->right;
            else {
                succ = root->data;
                root= root->left;
            }
        }        
        return succ;
    }
};