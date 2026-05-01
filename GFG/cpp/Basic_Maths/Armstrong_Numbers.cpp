// https://www.geeksforgeeks.org/problems/armstrong-numbers2727/1
#include<iostream>
#include<string>
using std::cout;
using std::string;

class Solution {
public:
    static string armstrongNumber(int n) {
        int sum=0;
        const int num = n;
        while(n){
            const int dig = n%10;
            sum+=dig*dig*dig;
            n/=10;
        }
        if(sum == num) return "true";
        return "false";
    }
};

int main() {
    Solution armNum;
    cout << armNum.armstrongNumber(371);
}
