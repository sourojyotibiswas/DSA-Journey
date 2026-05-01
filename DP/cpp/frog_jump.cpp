#include <bits/stdc++.h>
using namespace std;

// *** pattern : max of 1 or 2 step ***

// recursion:
class Solution1
{
public:
    int f(vector<int> &height, int n)
    {
        if (n == 0)
            return 0;

        // either 1 step:
        int one_step = f(height, n - 1) + abs(height[n] - height[n - 1]);
        // or 2 steps:
        int two_steps = INT_MAX;
        if (n > 1)
            two_steps = f(height, n - 2) + abs(height[n] - height[n - 2]);

        return min(one_step, two_steps);
    }
    int frog_jump_min_cost(vector<int> &height)
    {
        int n = height.size();
        return f(height, n - 1);
    }
};

// recursion + memoization:
class Solution2
{
public:
    int f(vector<int> &height, int n, vector<int> &dp)
    {
        if (n == 0)
            return 0;

        if (dp[n] != -1)
            return dp[n];

        // either 1 step:
        int one_step = f(height, n - 1, dp) + abs(height[n] - height[n - 1]);
        // or 2 steps:
        int two_steps = INT_MAX;
        if (n > 1)
            two_steps = f(height, n - 2, dp) + abs(height[n] - height[n - 2]);

        return dp[n] = min(one_step, two_steps);
    }
    int frog_jump_min_cost(vector<int> &height)
    {
        int n = height.size();
        vector<int> dp(n, -1);
        return f(height, n - 1, dp);
    }
};

// tabulation:
class Solution3
{
public:
    int frog_jump_min_cost(vector<int> &height)
    {
        int n = height.size();
        vector<int> dp(n);

        for (int i = 1; i < n; i++)
        {
            int one_step = dp[i - 1] + abs(height[i] - height[i - 1]);
            int two_steps = INT_MAX;
            if (i > 1)
                two_steps = dp[i - 2] + abs(height[i] - height[i - 2]);
            dp[i] = min(one_step, two_steps);
        }

        return dp[n - 1];
    }
};

// space optimization:
class Solution4
{
public:
    int frog_jump_min_cost(vector<int> &height)
    {
        int n = height.size();
        int prev = 0;      // -1
        int prev_prev = 0; // -2

        for (int i = 1; i < n; i++)
        {
            int one_step = prev + abs(height[i] - height[i - 1]);
            int two_steps = INT_MAX;
            if (i > 1)
                two_steps = prev_prev + abs(height[i] - height[i - 2]);

            prev_prev = prev;
            prev = min(one_step, two_steps);
        }

        return prev;
    }
};

int main()
{
    vector<int> heights(5);
    heights[0] = 30;
    heights[1] = 20;
    heights[2] = 50;
    heights[3] = 10;
    heights[4] = 40;

    Solution4 s;
    cout << s.frog_jump_min_cost(heights);

    return 0;
}