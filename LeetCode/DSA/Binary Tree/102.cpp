// LEVEL ORDER TRAVERSAL
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == nullptr) return ans;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int levelSize = q.size();           
            vector<int> level;

            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = q.front();
                q.pop();
                level.push_back(node->val);     

                if (node->left) q.push(node->left);   
                if (node->right) q.push(node->right); 
            }

            ans.push_back(level);               
        }

        return ans;
    }
};