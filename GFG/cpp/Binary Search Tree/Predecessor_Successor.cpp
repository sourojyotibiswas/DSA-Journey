class Solution {
  protected:
    void find_The_Succ(Node* root, int key, Node*& succ) {
        while (root) {
            if (root->data > key) {
                succ = root;  // potential successor
                root = root->left;
            } else {
                root = root->right;
            }
        }
    }

    void find_The_Pred(Node* root, int key, Node*& pred) {
        while (root) {
            if (root->data < key) {
                pred = root;  // potential predecessor
                root = root->right;
            } else {
                root = root->left;
            }
        }
    }

  public:
    vector<Node*> findPreSuc(Node* root, int key) {
        Node* pred = nullptr;
        Node* succ = nullptr;
        find_The_Succ(root, key, succ);
        find_The_Pred(root, key, pred);
        return {pred, succ};
    }
};