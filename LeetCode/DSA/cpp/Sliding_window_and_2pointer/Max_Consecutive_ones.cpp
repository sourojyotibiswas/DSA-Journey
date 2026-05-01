// https://leetcode.com/problems/max-consecutive-ones-iii/
#include <iostream>
#include <vector>
using namespace std;

// Time complexity: O(n) optimised solution
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int maxlen = 0, l=0, r=0, zeros=0;
        while(r<nums.size()){
            if(nums[r]==0) zeros++;
            if(zeros>k){
                if(nums[l]==0) zeros--;
                l++;
            }
            if(zeros<=k){
                int len=r-l+1;
                maxlen=max(len, maxlen);
            }
            r++;
        }
        return maxlen;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1,1,1,0,0,0,1,1,1,1,0};
    int k = 2;
    cout << "The longest sequence of 1s with at most " << k << " zeros is: " << sol.longestOnes(nums, k) << endl;
    return 0;
}