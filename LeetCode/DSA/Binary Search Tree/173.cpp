// BINARY SEARCH TREE NEXT AND BEFORE ITERATOR
// NEXT
// class BSTIterator {
//     stack<TreeNode* > myStack;
// public:
//     BSTIterator(TreeNode* root) {
//         pushAll(root);
//     }
    
//     int next() {
//         TreeNode* tmpNode = myStack.top();
//         myStack.pop();
//         pushAll(tmpNode->right);
//         return tmpNode->val;
//     }
    
//     bool hasNext() {
//         return !myStack.empty();
//     }

//     void pushAll(TreeNode* node){
//         for(; node != nullptr; myStack.push(node), node = node->left);
//     }
// };

class BSTIterator {
    stack<TreeNode*> st;

public:
    // Constructor: Initialize stack with leftmost path from root
    BSTIterator(TreeNode* root) {
        pushLeft(root);
    }

    // Returns the next smallest number
    int next() {
        TreeNode* node = st.top();
        st.pop();

        // If right child exists, push its leftmost path
        if (node->right) {
            pushLeft(node->right);
        }

        return node->val;
    }

    // Returns true if there is a next smallest number
    bool hasNext() {
        return !st.empty();
    }

private:
    // Helper function to push all left children to the stack
    void pushLeft(TreeNode* node) {
        while (node) {
            st.push(node);
            node = node->left;
        }
    }
};

// BEFORE
class BSTReverseIterator {
    stack<TreeNode*> myStack;

public:
    BSTReverseIterator(TreeNode* root) {
        pushAll(root);
    }

    int prev() {
        TreeNode* tmpNode = myStack.top();
        myStack.pop();
        pushAll(tmpNode->left);  // Go to left subtree (smaller elements)
        return tmpNode->val;
    }

    bool hasPrev() {
        return !myStack.empty();
    }

private:
    void pushAll(TreeNode* node) {
        for (; node != nullptr; myStack.push(node), node = node->right);
    }
};
