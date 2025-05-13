// VERTICAL ORDER TRAVERSAL
/*
        3
       / \
      9  20
         / \
       15   7
*/
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // data structures used
        //(vertical, level, multinodes)
        map<int, map<int, multiset<int>>> nodes;

        // (node, vertical, level)
        queue<pair<TreeNode*, pair<int, int>>> todo;

        // pushed the root node initially
        todo.push({root, {0,0}});

        // iterating the queue until its empty
        while(!todo.empty()){

            // taking out the first element in queue
            auto p = todo.front();
            todo.pop();

            // storing each element in a variable
            TreeNode* node = p.first;
            int x = p.second.first;
            int y = p.second.second;

            // inserting the elements in nodes data structure
            nodes[x][y].insert(node -> val);

            // now go for its left ans right nodes and push it to queue
            if(node -> left){
                todo.push({node->left, {x-1, y+1}});
            }
            if(node -> right){
                todo.push({node->right, {x+1, y+1}});
            }
        }

        /*
        Final nodes in Map structure
        {
           -1: {1: {9}},           
            0: {0: {3}, 2: {15}},  
            1: {1: {20}},          
            2: {2: {7}}            
        }        
        */

        vector<vector<int>> ans;  // This will store the final answer
        for(auto p : nodes){      // Iterate over each vertical (x-coordinate)
            vector<int> col;      // Stores nodes in the current vertical line
            for(auto q : p.second){  // Iterate over each level (y-coordinate) in the current vertical
                col.insert(col.end(), q.second.begin(), q.second.end());  // Append all nodes at (x,y)
            }
            ans.push_back(col);   // Add the current vertical line to the answer
        }
    return ans;               // Return the final answer
    /*
      [
        [9],       // Vertical -1
        [3, 15],   // Vertical 0
        [20],      // Vertical 1
        [7]        // Vertical 2
      ]
    */
    }
};

// Why multiset?
// If two nodes had the same (vertical, level) (e.g., (0, 2) = {15, 18}), multiset ensures they are stored in ascending order.