// OPTIMAL SOLUTION TO MAXIMUM SUBARRAY SUM PROBLEM

#include <iostream>
#include <vector>
#include <algorithm>

int maxSubArraySum(const std::vector<int>& nums) {
    int max_so_far = nums[0];
    int max_ending_here = nums[0];

    for (size_t i = 1; i < nums.size(); ++i) {
        max_ending_here = std::max(nums[i], max_ending_here + nums[i]);
        max_so_far = std::max(max_so_far, max_ending_here);
    }

    return max_so_far;
}

int main() {
    std::vector<int> nums = {-2, 3, 2, -1};
    std::cout << "Maximum subarray sum is " << maxSubArraySum(nums) << std::endl;
    return 0;
}