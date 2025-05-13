// DIAMETER OF A BINARY TREE: LONGEST PATH B/W ANY TWO NODES.

#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int maxDiameter = 0;

    int height(TreeNode* node) {
        if (!node) return 0;

        int leftHeight = height(node->left);
        int rightHeight = height(node->right);

        maxDiameter = max(maxDiameter, leftHeight + rightHeight);

        return 1 + max(leftHeight, rightHeight);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int p = height(root);
        cout<< "height function last return: " << p <<"\n"; // just to check the dry run
        return maxDiameter;
    }
};

int main() {
    // Construct the tree:
    //       1
    //      / \
    //    2    3
    //         / \
    //       4    7 
    //      /       \
    //    5          8
    //   /            \
    //  6              9

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(7);
    root->right->left->left = new TreeNode(5);
    root->right->left->left->left = new TreeNode(6);
    root->right->right->right = new TreeNode(8);
    root->right->right->right->right = new TreeNode(9);

    Solution sol;
    int diameter = sol.diameterOfBinaryTree(root);

    cout << "Diameter of the tree: " << diameter << endl;

    return 0;
}
