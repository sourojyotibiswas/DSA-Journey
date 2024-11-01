// https://www.geeksforgeeks.org/problems/sum-of-all-divisors-from-1-to-n4738/1
#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
using std::ranges::sort; // Introduced in C++20
using std::vector;
using std::cout;

class Solution
{
public:
    // Print all the divisors of N
    static void printAllDivisors(const int num) {
        vector<int> v;
        for(int i=1; i <= sqrt(num); i++) {
            if(num%i==0) {
                v.push_back(i);
                if(i != num/i) v.push_back(num/i);
            }
        }
        sort(v);
        for (const int i: v) {
            std::cout << i << " ";
        }
    }
};

int main() {
    Solution sol;
    sol.printAllDivisors(36);
}