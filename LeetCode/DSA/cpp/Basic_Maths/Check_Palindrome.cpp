// https://leetcode.com/problems/palindrome-number/
#include<iostream>
#include<limits>
using std::numeric_limits;
using std::cout;

class Solution {
public:
    static bool isPalindrome(int x) {
        const long int rev = x;
        long int num = 0;
        if(x < 0) return false;
        while (x != 0) {
            const int rem = x % 10;
            x /= 10;
            if (num > numeric_limits<int>::max() ||
                (num == numeric_limits<int>::max() / 10 && rem > 7))
                return false;
            if (num < numeric_limits<int>::min() ||
                (num == numeric_limits<int>::min() / 10 && rem < -8))
                return false;

            num = num * 10 + rem;
        }
        return (rev == num);
    }
};

int main() {
    Solution sol;
    cout<< sol.isPalindrome(32413);
}