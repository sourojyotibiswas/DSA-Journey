// https://leetcode.com/problems/binary-subarrays-with-sum/description/

#include <iostream>
#include <vector>
using namespace std;

/**
 * Time Complexity: O(n), where n is the length of the input array `nums`. The algorithm processes each element of the array at most twice.
 * Space Complexity: O(1), as the algorithm uses a constant amount of extra space.
 */

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atMost(nums, goal) - (goal > 0 ? atMost(nums, goal - 1) : 0);
    }
    
private:
    int atMost(const vector<int>& nums, int maxSum) {
        int l = 0, sum = 0, count = 0;
        for (int r = 0; r < nums.size(); r++) {
            sum += nums[r];
            
            // Shrink the window if the sum exceeds maxSum
            while (sum > maxSum) {
                sum -= nums[l];
                l++;
            }
            
            // Count subarrays with sum at most maxSum
            count += (r - l + 1);
        }
        return count;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 0, 1, 0, 1};
    int goal = 2;
    int result = solution.numSubarraysWithSum(nums, goal);
    cout << "Number of subarrays with sum " << goal << " is: " << result << endl;
    return 0;
}