/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    TreeNode* solve(int &i, vector<int> &preorder, int lb, int ub) {
        // bc
        if (i >= preorder.size()) {
            return nullptr;
        }

        // check it is out of bound or not
        if (!(lb < preorder[i]) || !(preorder[i] < ub)) {
            return nullptr;
        }

        // valid
        TreeNode* root = new TreeNode(preorder[i]);
        i++;
        root->left = solve(i, preorder, lb, root->val);
        root->right = solve(i, preorder, root->val, ub);

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        // 01 approach - insert always from root - o(n2)

        // 02 approach - inorder sort + make bst - o(nlogn)

        // 03 approach - range checking - o(n)
        int i = 0;
        int lb = INT_MIN;
        int ub = INT_MAX;
        return solve(i, preorder, lb, ub);
    }
};