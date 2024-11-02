// https://leetcode.com/problems/subarray-sum-equals-k/description/

#include <iostream>
#include <vector>
#include <map>
using namespace std;

// Time complexity: O(nlogn) optimised solution for map and O(n) for unordered_map in best case and O(n^2) in worst case
// space complexity: O(n)
int findAllSubarraysWithGivenSum(vector < int > & arr, int k) {
    int n = arr.size(); // size of the given array.
    map<int, int>  mp; // map to store the prefix sum and its frequency.
    mp[0] = 1; // Setting 0 in the map.
    int preSum = 0, cnt = 0;

    for (int i = 0; i < n; i++) {
        // add current element to prefix Sum:
        preSum += arr[i];

        // Calculate x-k:
        int remove = preSum - k;

        // Add the number of subarrays to be removed:
        cnt += mp[remove];

        // Update the count of prefix sum
        // in the map.
        mp[preSum] += 1;
    }
    return cnt;
}

int main()
{
    vector arr = {1};
    int k = 0;
    int cnt = findAllSubarraysWithGivenSum(arr, k);
    cout << "The number of subarrays is: " << cnt << "\n";
    return 0;
}

