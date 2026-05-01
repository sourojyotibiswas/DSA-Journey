class Solution {
  public:
    vector<int> leftView(Node *root) {
        // code here
        vector<int> ans;
        if(root == nullptr) return ans;
        
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()){
            int qSize = q.size();
            int num;
            for(int i=0; i<qSize; ++i){
                Node* node = q.front();
                q.pop();
                
                if(i==0) num = node->data;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            ans.push_back(num);
        }
        return ans;
    }
};
