#include <bits/stdc++.h>
using namespace std;

// *** pattern : pick and non pick ***

// recursion:
class Solution1
{
public:
    int f(vector<int> &house, int n)
    {
        // if we are at 0 that means we haven't picked 1 so pick the 0
        if (n == 0)
            return house[0];
        // since n can go -ve so we have to handle that case
        if (n < 0)
            return 0;

        int pick = house[n] + f(house, n - 2);
        int non_pick = 0 + f(house, n - 1);

        return max(pick, non_pick);
    }
    int house_rob(vector<int> &house)
    {
        int n = house.size();
        return f(house, n - 1);
    }
};

// recursion + memoization:

// tabulation:

// space optimization:

int main()
{
    vector<int> house(4);
    house[0] = 1;
    house[1] = 2;
    house[2] = 3;
    house[3] = 1;

    Solution1 s;
    cout << s.house_rob(house);

    return 0;
}