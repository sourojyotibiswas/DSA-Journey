// https://www.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=longest-sub-array-with-sum-k


#include <iostream>
#include <vector>
#include <map>
#include <sstream>
#include <string>
using namespace std;

// optimal solution for +ve, -ve and 0 elements
// time complexity: O(nlogn) -> for ordered map and O(n) for unordered map in best case and O(n^2) in worst case
// space complexity: O(n)
// class Solution {
//   public:
//     int lenOfLongestSubarr(vector<int>& arr, int k) {
//         map<int, int> preSumMap;
//         int sum=0;
//         int maxlen=0;
//         for(int i=0;i<arr.size();i++){
//             sum+=arr[i];
//             if(sum==k){
//                 maxlen = max(maxlen, i+1);
//             }
//             int rem = sum-k;
//             if(preSumMap.find(rem)!=preSumMap.end()){
//                 int len = i-preSumMap[rem];
//                 maxlen=max(maxlen, len);
//             }
//             if(preSumMap.find(sum)==preSumMap.end()){
//                 preSumMap[sum]=i;
//             }
//         }
//         return maxlen;
//     }
// };

// optimal solution for +ve and 0 elements
// time complexity: O(n)
// space complexity: O(1)
class Solution {
  public:
    int lenOfLongestSubarr(vector<int>& arr, int k) {
        int left=0, right=0,sum=0, sum1=arr[0], maxlen=0;
        int n=arr.size();

        while(right<n){
            if(sum==k){
                maxlen=max(maxlen, right-left+1);
                right++;
                if(right<n) sum+=arr[right];
            } else if(sum<k){
                right++;
                if(right<n) sum+=arr[right];
            } else {
                sum-=arr[left];
                left++;
            }
        }

        // ============ OR ============

        while(right<n){
            while(left<=right && sum1>k){
                sum1-=arr[left];
                left++;
            }
            if(sum1==k){
                maxlen=max(maxlen, right-left+1);
            }
            right++;
            if(right < n) sum1+=arr[right];
        }
        return maxlen;
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--) {
        vector<int> arr;
        int k;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> k;
        cin.ignore(); // Ignore newline character after k input

        Solution solution;
        cout << solution.lenOfLongestSubarr(arr, k) << "\n";
        cout << "~\n";
    }

    return 0;
}

