// https://leetcode.com/problems/subarrays-with-k-different-integers/description/

#include <iostream>
#include <vector>
#include <unordered_map>
using std::vector;
using std::unordered_map;
using std::cout;
using std::cin;

/**
    * The idea is to count the number of subarrays with at most k distinct elements.
    * Then, we can find the number of subarrays with exactly k distinct elements by subtracting the number of subarrays with at most k - 1 distinct elements.

    * Time complexity: O(2n) -> O(n)
    * Space complexity: O(n)
*/

class Solution {
private:
    int func(vector<int>& nums, int k) {
        int l = 0, r = 0, count = 0;
        unordered_map<int, int> mpp;
        while (r < nums.size()) {
            mpp[nums[r]]++;  // Add the current element to the map
            while (mpp.size() > k) {  // If more than k distinct elements, shrink the window
                mpp[nums[l]]--;
                if (mpp[nums[l]] == 0) mpp.erase(nums[l]);
                l++;
            }
            count += (r - l + 1);  // Count subarrays ending at index r
            r++;
        }
        return count;
    }

public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        // Subarrays with exactly k distinct elements
        return func(nums, k) - func(nums, k - 1);
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 2, 1, 2, 3};
    int k = 2;
    cout << s.subarraysWithKDistinct(nums, k) << '\n';
    return 0;
}