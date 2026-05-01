// MAXIMUM PATH SUM OF A BINARY TREE
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int sum = INT_MIN;
        maxSum(root, sum);
        return sum;
    }
    int maxSum(TreeNode* root, int &sum){
        if(!root) return 0;

        int leftSum = max(0, maxSum(root->left, sum));
        int rightSum = max(0, maxSum(root->right, sum));

        sum = max(sum, leftSum + rightSum + root->val);
        return (root->val)+max(leftSum, rightSum);
    }
};