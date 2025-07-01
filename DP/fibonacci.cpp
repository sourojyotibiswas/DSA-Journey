#include <bits/stdc++.h>
using namespace std;

// Recursion
class Solution1
{
public:
    int f(int n)
    {
        if (n < 2)
            return n;
        return f(n - 1) + f(n - 2);
    }

    int fib(int n)
    {
        return f(n);
    }
};

// Recursion + Memoization
class Solution2
{
public:
    int f(int n, vector<int> &dp)
    {
        // base case:
        if (n < 2)
            return n;

        if (dp[n] != 0)
            return dp[n];
        return dp[n] = f(n - 1, dp) + f(n - 2, dp);
    }

    int fib(int n)
    {
        vector<int> dp(n + 1, 0);
        return f(n, dp);
    }
};

// tabulation
class Solution3
{
public:
    int fib(int n)
    {
        vector<int> dp(n + 1);
        // base case:
        dp[0] = 0;
        dp[1] = 1;

        // copy the recursion:
        for (int i = 2; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];
    }
};

// space optimization
class Solution4
{
public:
    int fib(int n)
    {
        if (n < 2)
            return n;

        int prev_prev = 0;
        int prev = 1;

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
    cout << s.fib(n);
    return 0;
}