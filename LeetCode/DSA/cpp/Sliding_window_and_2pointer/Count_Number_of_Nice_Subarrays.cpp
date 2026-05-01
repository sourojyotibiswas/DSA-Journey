// https://leetcode.com/problems/count-number-of-nice-subarrays/description/

#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::endl;
using std::cin;

/**
    TC: O(n)
    SC: O(1)
**/

class Solution {
public:

    int numberOfSubarrays(vector<int>& nums, int k) {
        return numSubarraysWithSum(nums, k) - (k > 0 ? numSubarraysWithSum(nums, k - 1) : 0);
    }
private:
    int numSubarraysWithSum(vector<int>& nums, int k) {
            int l = 0, sum = 0, count = 0;
            for (int r = 0; r < nums.size(); r++) {
                sum += (nums[r] % 2);

                while (sum > k) {
                    sum -= (nums[l] % 2);
                    l++;
                }

                count += (r - l + 1);
            }
            return count;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {2,2,2,1,2,2,1,2,2,2};
    int k = 2;
    int result = solution.numberOfSubarrays(nums, k);
    cout << "Number of nice subarrays: " << result << endl;
    return 0;
}