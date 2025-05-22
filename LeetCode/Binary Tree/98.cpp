// VALIDATE BINARY SEARCH TREE
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        // LONG_MIN: -2147483648; LONG_MAX: 2147483647
        return isValid(root, LONG_MIN, LONG_MAX);        
    }

private:
    bool isValid(TreeNode* node, long minimum, long maximum) {
        if (!node) return true;

        if (!(node->val > minimum && node->val < maximum)) return false;

        return valid(node->left, minimum, node->val) && valid(node->right, node->val, maximum);
    }    
};

// #include <climits>
// #include <iostream>

// int main() {
//     std::cout << "LONG_MIN: " << LONG_MIN << std::endl;
//     std::cout << "LONG_MAX: " << LONG_MAX << std::endl;
//     return 0;
// }
