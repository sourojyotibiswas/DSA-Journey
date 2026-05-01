#include <bits/stdc++.h>
using namespace std;

// *** houses are in circular manner : checking by taking 1st house and then by taking last house ***

// recursion:
class Solution1
{
public:
    int f(vector<int> &houses, int n)
    {
        if (n == 0)
            return houses[0];
        if (n < 0)
            return 0;

        int pick_house = houses[n] + f(houses, n - 2);
        int not_pick_house = 0 + f(houses, n - 1);

        return max(pick_house, not_pick_house);
    }
    int house_rob(vector<int> &houses)
    {
        int n = houses.size();
        // create two temp vectors
        vector<int> temp1, temp2;

        // edge case if there is a single house
        if (n == 1)
            return houses[0];

        // inside one push all elements except 0
        // and in another push all elements except n-1
        for (int i = 0; i < n; i++)
        {
            if (i != 0)
                temp1.push_back(houses[i]);
            if (i != n - 1)
                temp2.push_back(houses[i]);
        }

        // then check which one gives you max
        return max(f(temp1, temp1.size() - 1), f(temp2, temp2.size() - 1));
    }
};

// recursion + memoization:
class Solution2
{
public:
    int f(vector<int> &houses, int n, vector<int> &dp)
    {
        if (n == 0)
            return houses[0];
        if (n < 0)
            return 0;

        if (dp[n])
            return dp[n];

        int pick_house = houses[n] + f(houses, n - 2, dp);
        int not_pick_house = 0 + f(houses, n - 1, dp);

        return dp[n] = max(pick_house, not_pick_house);
    }
    int house_rob(vector<int> &houses)
    {
        int n = houses.size();
        // create two temp vectors
        vector<int> temp1, temp2;
        vector<int> dp(n);

        // edge case if there is a single house
        if (n == 1)
            return houses[0];

        // inside one push all elements except 0
        // and in another push all elements except n-1
        for (int i = 0; i < n; i++)
        {
            if (i != 0)
                temp1.push_back(houses[i]);
            if (i != n - 1)
                temp2.push_back(houses[i]);
        }

        // then check which one gives you max
        return max(f(temp1, temp1.size() - 1, dp), f(temp2, temp2.size() - 1, dp));
    }
};

// tabulation:
class Solution3
{
public:
};

int main()
{
    Solution2 s;

    // Example test case
    vector<int> houses = {2, 3, 2};
    cout << s.house_rob(houses);

    return 0;
}