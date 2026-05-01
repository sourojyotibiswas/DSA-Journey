// https://www.geeksforgeeks.org/problems/fruit-into-baskets-1663137462/1

#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

/**
    TC: O(N)
    SC: O(1)
**/

class Solution {
public:
    int totalFruits(vector<int>& arr) {
        int n = arr.size();
        int left = 0, maxlen = 0;
        unordered_map<int, int> mp;
        
        for (int right = 0; right < n; ++right) {
            mp[arr[right]]++;
                       
            if (mp.size() > 2) {
                mp[arr[left]]--;
                if (mp[arr[left]] == 0) {
                    mp.erase(arr[left]);
                }
                left++;
            }

            maxlen = max(maxlen, right - left + 1);
        }
        
        return maxlen;
    }
};

#include <iostream>

int main() {
    Solution sol;
    vector<int> fruits = {3, 1, 2, 2, 2, 2};
    cout << "Maximum number of fruits: " << sol.totalFruits(fruits) << endl;
    return 0;
}

/***
int totalFruits(int N, vector<int> &fruits) {
        int f = -1; // first fruit type
        int s = -1; // second fruit type

        int l = 0; // left pointer
        int r = 0; // right pointer
        int ans = 0;

        while (r < N) {
            if (f == -1 || fruits[r] == fruits[f]) {
                f = r;
            } else if (s == -1 || fruits[r] == fruits[s]) {
                s = r;
            } else {
                // When a new fruit type is encountered
                if (f < s) {
                    l = f + 1;
                    f = r;
                } else {
                    l = s + 1;
                    s = r;
                }
            }
            ans = max(ans, r - l + 1);
            r++;
        }

        return ans;
    }

 */