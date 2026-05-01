// https://leetcode.com/problems/reverse-integer/
#include<iostream>
#include<limits>
using std::numeric_limits;
using std::cout;

class Solution {
public:
    static int reverse1(int x) {
        int num = 0;
        while(x) {
            const int rem = x%10;
            num = num*10 + rem;
            x/=10;
        }
        return num;
    }

    // Optimized solution within the 32-bit integer range:
    static int reverse2(int x) {
        int reversed = 0;
        while (x != 0) {
            const int digit = x % 10;
            x /= 10;

            if (reversed > numeric_limits<int>::max() / 10 ||
                (reversed == numeric_limits<int>::max() / 10 && digit > 7)) {
                return 0; // Overflow
                }
            if (reversed < numeric_limits<int>::min() / 10 ||
                (reversed == numeric_limits<int>::min() / 10 && digit < -8)) {
                return 0; // Underflow
                }

            reversed = reversed * 10 + digit;
        }
        return reversed;
    }
};

int main() {
    Solution a;
    cout<< a.reverse1(12345) <<"\n";
    cout << a.reverse2(-1276500);
}