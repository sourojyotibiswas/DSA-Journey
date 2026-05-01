// RIGHT VIEW OF A BINARY TREE
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root == nullptr) return ans;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int qSize = q.size();
            int num;

            for(int i=0; i<qSize; i++){
                TreeNode* node = q.front();
                q.pop();

                if(i == qSize-1) num = node->val; // rather than storing the value in extra variable just push the value in ans vector here itself.
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right); 
            }
            ans.push_back(num);
        }
        return ans;
    }
};