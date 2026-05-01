// https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/description/

#include<iostream>
#include<vector>
using std::vector;
using std::cout;
using std::max;
using std::cin;

/**
Time Complexity: O(2k)
Space Complexity: O(1) 
*/

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int l_sum=0, r_sum=0, max_sum=0;
        for(int i=0; i<k; i++) l_sum+=cardPoints[i];
        max_sum=l_sum;
        int r_index=cardPoints.size()-1;
        for(int i=k-1; i>=0; i--){
            l_sum=l_sum-cardPoints[i];
            r_sum=r_sum+cardPoints[r_index];
            r_index=r_index-1;
            max_sum=max(max_sum, l_sum+r_sum);
        }
        return max_sum;
    }
};

/** input format: 
7 3
1 2 3 4 5 6 1
*/
int main(){
    Solution s;
    vector<int> cardPoints;
    int n, k;
    cin>>n>>k;
    for(int i=0; i<n; i++){
        int temp;
        cin>>temp;
        cardPoints.push_back(temp);
    }
    cout<<s.maxScore(cardPoints, k);
    return 0;
}

/** for comma separated inputs:
7 3
1,2,3,4,5,6,1

#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

int main() {
    Solution s;
    vector<int> cardPoints;
    int n, k;
    cin >> n >> k;
    cin.ignore(); // Ignore the newline after k

    string line;
    getline(cin, line); // Read the entire line of comma-separated values

    // Use stringstream to process the comma-separated values
    stringstream ss(line);
    string temp;
    while (getline(ss, temp, ',')) {
        cardPoints.push_back(stoi(temp)); // Convert each substring to an integer
    }

    cout << s.maxScore(cardPoints, k);
    return 0;
}
*/
