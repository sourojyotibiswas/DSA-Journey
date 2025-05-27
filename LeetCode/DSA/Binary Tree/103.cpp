// ZIG ZAG LEVEL ORDER TRAVERSAL
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
         vector<vector<int>> ans;
        if (root == nullptr) return ans;

        queue<TreeNode*> q;
        q.push(root);
        bool leftToRight = true;

        while (!q.empty()) {
            int levelSize = q.size();           
            vector<int> level(levelSize); // to access the index you need to allocate space

            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = q.front();
                q.pop();

                int index = (leftToRight)?i:(levelSize-1-i);
                level[index] = node->val;   

                if (node->left) q.push(node->left);   
                if (node->right) q.push(node->right); 
            }

            ans.push_back(level);
            leftToRight = !leftToRight;               
        }
        return ans;
    }
};