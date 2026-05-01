class Solution {
public:

    Node* connect(Node* root) {
        
        // empty
        if (!root) return nullptr;
        // single
        if (!root->left && !root->right) return root;

        //01 approach - sc = o(n)
        // lot
        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int n = q.size();

            // operation on all sibling nodes
            for (int i = 0; i<n; i++) {
                auto front = q.front();
                q.pop();

                // last node
                if (i == n-1) {
                    front->next = nullptr;
                }
                // not last node
                else {
                    front->next = q.front();
                }

                // insert children if exists
                if (front->left) q.push(front->left);
                if (front->right) q.push(front->right);
            }
        }

        return root;


        // // 02 approach - sc = o(1)
        // Node* level = root;

        // // bc it perfect binary tree
        // while (level->left) {

        //     Node* curr = level;
        //     // upper level already connected
        //     while (curr) {
        //         // connect left child to right child
        //         if (curr->left) curr->left->next = curr->right;
        //         // connect right child to next node's left child
        //         if (curr->right && curr->next) curr->right->next = curr->next->left;

        //         curr = curr->next;
        //     }
        //     level = level->left;
        // }

        // return root;
    }
};