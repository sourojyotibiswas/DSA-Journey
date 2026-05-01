#include <bits/stdc++.h>
using namespace std;

// *** same as house robber : pick and non pick ***

// recursion + memoization
class Solution1
{
public:
    int f(int i, vector<int> &nums, vector<int> &dp)
    {
        // base case
        if (i == 0)
            return nums[i];
        if (i < 0)
            return 0;

        if (dp[i] != -1)
            return dp[i];

        // if picked ith element then add it with the others
        int pick = nums[i] + f(i - 2, nums, dp);
        // if not picked ith element then skip and go to next element and start
        int not_pick = f(i - 1, nums, dp);

        return dp[i] = max(pick, not_pick);
    }
    int maximumNonAdjacentSum(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n, -1);
        return f(n - 1, nums, dp);
    }
};

// tabulation
class Solution2
{
public:
    int maximumNonAdjacentSum(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
            return 0;

        vector<int> dp(n);
        dp[0] = nums[0];
        // dp[1] = max(nums[0], nums[1]);

        for (int i = 1; i < n; i++)
        {
            int pick = nums[i];
            if (i > 1)
                pick += dp[i - 2];
            int not_pick = dp[i - 1];
            dp[i] = max(pick, not_pick);
        }

        return dp[n - 1];
    }
};

// space optimization
class Solution3
{
public:
    int maximumNonAdjacentSum(vector<int> &nums)
    {
        int n = nums.size();
        int prev1 = nums[0];
        int prev2 = 0;

        for (int i = 1; i < n; i++)
        {
            int pick = nums[i];
            if (i > 1)
                pick += prev2;
            int not_pick = prev1;

            int curr = max(pick, not_pick);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};

int main()
{
    vector<int> nums = {5, 5, 10, 100, 10, 5};

    Solution1 s;
    cout << s.maximumNonAdjacentSum(nums);

    return 0;
}