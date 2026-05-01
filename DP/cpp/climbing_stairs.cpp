#include <bits/stdc++.h>
using namespace std;

// *** similar to fibonacci series ***

// recursion:
class Solution1
{
public:
    int f(int n)
    {
        if (n < 2)
            return 1;

        return f(n - 1) + f(n - 2);
    }
    int climbStairs(int n)
    {
        return f(n);
    }
};

// recursion + memoization:
class Solution2
{
public:
    int f(int n, vector<int> &dp)
    {
        if (n < 2)
            return 1;

        if (dp[n])
            return dp[n];

        return dp[n] = f(n - 1, dp) + f(n - 2, dp);
    }
    int climbStairs(int n)
    {
        vector<int> dp(n + 1);
        return f(n, dp);
    }
};

// tabulation:
class Solution3
{
public:
    int climbStairs(int n)
    {
        vector<int> dp(n + 1);
        dp[1] = 1;
        dp[0] = 1;

        for (int i = 2; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};

// space optimization:
class Solution4
{
public:
    int climbStairs(int n)
    {
        int prev = 1;      // -1
        int prev_prev = 1; // -2

        for (int i = 2; i <= n; i++)
        {
            int ans = prev + prev_prev;
            prev_prev = prev;
            prev = ans;
        }
        return prev;
    }
};

int main()
{
    int n;
    cin >> n;
    Solution4 s;
    cout << s.climbStairs(n);
    return 0;
}