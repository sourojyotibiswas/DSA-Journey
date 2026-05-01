// This function should return head to the DLL
class Solution {
  public:
    Node* prev = NULL;
    Node* head = NULL;

    Node* bToDLL(Node* root) {
        if (root == NULL) return NULL;

        // Traverse left subtree
        bToDLL(root->left);

        // Process current node
        if (prev == NULL) {
            head = root;  // This is the leftmost node, becomes head of DLL
        } else {
            root->left = prev;
            prev->right = root;
        }

        prev = root;

        // Traverse right subtree
        bToDLL(root->right);

        return head;  // ✅ Return the head of the DLL
    }
};