// BOUNDARY OF BINARY TREE
/*
Given a binary tree, return the values of its boundary in anti-clockwise direction starting from root,
Boundary includes left boundary, leaves and right boundary in order without duplicate nodes
(the values of nodes may still be duplicates.)

Left boundary is defined as the path from root to the left-most node. Right boundary is defined as the 
path from root to the right-most node. If the root doesn’t have left subtree or right subtree, then the 
root itself is left boundary or right boundary. Note this definition only applies to the input binary tree, 
and not applies to any subtrees.
The left-most node is defined as a leaf node you could reach when you always firstly travel to the 
left subtree if exists. If not, travel to the right subtree. Repeat until you reach a leaf node.
The right-most node is also defined by the same way with left and right exchanged.
*/

class Solution {
  private:
    bool isLeaf(Node* root){
        return (!root->left && !root->right)?true:false;
    }
    void addLeftBoundary(Node* root, vector<int> &ans){
        Node* curr = root->left;
        while(curr){
            if(!isLeaf(curr)) ans.push_back(curr->data);
            if(curr->left) curr = curr->left;
            else curr = curr->right;
        }
    }
    void addLeaves(Node* root, vector<int> &ans){
        if(isLeaf(root)){
            ans.push_back(root->data);
            return;
        }
        if(root->left) addLeaves(root->left, ans);
        if(root->right) addLeaves(root->right, ans);
    }
    void addRightBoundary(Node* root, vector<int> &ans){
        Node* curr = root->right;
        vector<int> temp;
        while(curr){
            if(!isLeaf(curr)) temp.push_back(curr->data);
            if(curr->right) curr = curr->right;
            else curr = curr->left;
        }
        for(int i=temp.size()-1; i>=0; --i){
            ans.push_back(temp[i]);
        }
    }
  public:
    vector<int> boundaryTraversal(Node *root) {
        // vector to store the result
        vector<int> ans;

        // base case if there is no root
        if(!root) return ans;
        // check for 1 node only that should not be leaf
        if(!isLeaf(root)) ans.push_back(root->data);
        
        // otherwise
        addLeftBoundary(root, ans);
        addLeaves(root, ans);
        addRightBoundary(root, ans);
        return ans;
    }
};