class Solution {
  public:
    int isSumProperty(Node *root) {
        if (root == nullptr || (root->left == nullptr && root->right == nullptr))
        return true;

        int left = 0, right = 0;

        if (root->left) {
            left = root->left->data;
        }

        if (root->right) {
            right = root->right->data;
        }

        bool leftCheck = isSumProperty(root->left);
        bool rightCheck = isSumProperty(root->right);

        return (root->data == left + right) && leftCheck && rightCheck;
    }
};