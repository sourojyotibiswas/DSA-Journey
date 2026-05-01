class Solution {
public:

    TreeNode* solve(int s, int e, vector<int> &nums) {
        // bc
        if (s > e) {
            return NULL;
        }

        // ek case mai sambhalunga
        // make node of mid
        int mid = s + ((e-s)>>1);
        // create mid node
        TreeNode* root = new TreeNode(nums[mid]);

        // left call
        root->left = solve(s, mid-1, nums);
        // right call
        root->right = solve(mid+1, e, nums);

        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int s = 0;
        int e = nums.size()-1;

        return solve(s, e, nums);
    }
};