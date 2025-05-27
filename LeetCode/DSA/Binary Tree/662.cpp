// MAX. WIDTH OF A BINARY TREE
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        // if no root ->
        if (!root) return 0;

        // if root is present ->
        long long ans = 0;
        queue<pair<TreeNode*, long long>> q;  

        // push initial node to queue
        q.push({root, 0});
        
        // iterate over queue until its empty
        while (!q.empty()) {
            int size = q.size();
            long long mmin = q.front().second;  
            long long first, last;
            
            for (int i = 0; i < size; i++) {
                long long curr_id = q.front().second - mmin;  
                TreeNode* node = q.front().first;
                q.pop();
                
                if (i == 0) first = curr_id;         
                if (i == size - 1) last = curr_id;    
                
                // push the left and right child into the queue
                if (node->left) 
                    q.push({node->left, curr_id * 2 + 1});
                if (node->right) 
                    q.push({node->right, curr_id * 2 + 2});
            }

            // update the the width
            ans = max(ans, last - first + 1);
        }
        return (int)ans;
    }
};