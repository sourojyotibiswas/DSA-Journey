// https://leetcode.com/problems/perfect-number/description/
#include<iostream>
using std::cout;

class Solution {
public:
    static bool checkPerfectNumber(const int num) {
        const int n = num;
        int sum = 0;

        for(int i=1; i<=num/2; i++){
            if(num%i == 0) sum+=i;
        }

        return (n==sum);
    }
};

int main() {
    Solution sol;
    cout << sol.checkPerfectNumber(28);
}