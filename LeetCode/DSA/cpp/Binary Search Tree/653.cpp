// TWO SUM IV - INPUT IS BINARY SEARCH TREE
// USE THE CONCEPT OF NEXT AND BEFORE ITERATOR
class BSTIterator {
    stack<TreeNode*> st;
    bool reverse;

public:
    BSTIterator(TreeNode* root, bool isReverse) {
        reverse = isReverse;
        pushAll(root);
    }

    int next() {
        TreeNode* node = st.top();
        st.pop();

        if (!reverse)
            pushAll(node->right); 
        else
            pushAll(node->left);  

        return node->val;
    }

    bool hasNext() {
        return !st.empty();
    }

private:
    void pushAll(TreeNode* node) {
        while (node != nullptr) {
            st.push(node);
            node = (reverse ? node->right : node->left);
        }
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if (!root) return false;

        BSTIterator l(root, false); // for next 
        BSTIterator r(root, true);   // for before

        int i = l.next();
        int j = r.next();

        while (i < j) {
            int sum = i + j;
            if (sum == k) return true;
            else if (sum < k) i = l.next();
            else j = r.next();
        }
        return false;
    }
};