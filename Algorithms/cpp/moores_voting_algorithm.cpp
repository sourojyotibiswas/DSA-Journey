#include <iostream>
#include <vector>

int findCandidate(const std::vector<int>& nums) {
    int candidate = nums[0];
    int count = 1;

    for (size_t i = 1; i < nums.size(); ++i) {
        if (nums[i] == candidate) {
            ++count;
        } else {
            --count;
        }

        if (count == 0) {
            candidate = nums[i];
            count = 1;
        }
    }

    return candidate;
}

bool isMajority(const std::vector<int>& nums, int candidate) {
    int count = 0;
    for (int num : nums) {
        if (num == candidate) {
            ++count;
        }
    }
    return count > nums.size() / 2;
}

int mooresVotingAlgorithm(const std::vector<int>& nums) {
    int candidate = findCandidate(nums);
    if (isMajority(nums, candidate)) {
        return candidate;
    } else {
        return -1; // No majority element found
    }
}

int main() {
    std::vector<int> nums = {2,3,4,3,3};
    int result = mooresVotingAlgorithm(nums);

    if (result != -1) {
        std::cout << "The majority element is " << result << std::endl;
    } else {
        std::cout << "No majority element found" << std::endl;
    }

    return 0;
}