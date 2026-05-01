class Solution {
  public:
    void help(Node* root, vector<int>& path, vector<vector<int>>& result) {
        if (!root) return;

        path.push_back(root->data);

        // If it's a leaf node, store the path
        if (!root->left && !root->right) {
            result.push_back(path);
        }

        // Recur for left and right children
        help(root->left, path, result);
        help(root->right, path, result);

        // Backtrack
        path.pop_back();
    }

    vector<vector<int>> Paths(Node* root) {
        vector<vector<int>> result;
        vector<int> path;
        help(root, path, result);
        return result;
    }
};
