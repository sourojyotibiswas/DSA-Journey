// PRINT ROOT TO GIVEN NODE PATH IN A BINARY TREE

#include <iostream>
#include <vector>
using namespace std;

// Tree Node definition
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool getPath(TreeNode* root, vector<int> &arr, int x) {
        if (!root) return false;

        arr.push_back(root->val);

        if (root->val == x) return true;

        if (getPath(root->left, arr, x) || getPath(root->right, arr, x)) return true;

        arr.pop_back();
        return false;
    }

    vector<int> solve(TreeNode* A, int B) {
        vector<int> arr;
        getPath(A, arr, B);
        return arr;
    }
};

// Helper function to print a vector
void printVector(const vector<int>& v) {
    for (int num : v) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    /*
          1
        /   \
       2     3
      / \       
     4   5      
        / \
       6   7
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->left = new TreeNode(6);
    root->left->right->right = new TreeNode(7);

    int target = 7;

    Solution sol;
    vector<int> path = sol.solve(root, target);

    cout << "Path from root to node " << target << ": ";
    printVector(path);

    return 0;
}

// PRINT ALL THE PATHS FROM ROOT TO LEAVES IN A BINARY TREE

class Solution {
public:
    void help(TreeNode* root, string path, vector<string>& result) {
        if (!root) return;

        // Append current node's value to the path
        if (!path.empty()) {
            path += "->";
        }
        path += to_string(root->val);

        // If it's a leaf, add the path to the result
        if (!root->left && !root->right) {
            result.push_back(path);
            return;
        }

        // Recur for left and right children
        help(root->left, path, result);
        help(root->right, path, result);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        help(root, "", result);
        return result;
    }
};