// https://www.geeksforgeeks.org/problems/count-digits5716/1
#include<iostream>
#include<cmath>
using std::cout;

class Count_Digits {
public:
    static int evenlyDivides(int N) {
        int count = 0;
        const int original = N;
        while(N) {
            if(const int rem = N % 10; rem != 0 && original % rem == 0) count++; // Introduced in C++17: if-with-initializer
            N /= 10;
        }
        return count;
    }

    // Recursive Approach: Time C. = O(log10(N)) due to recursive stack space
    static int countNoDigits1(int N) {
        // Base case: if N is 0, it has 1 digit
        if (N == 0) {
            return 1;
        }
        // Base case: if N is less than 0, make it positive
        if (N < 0) {
            N = -N;
        }
        if (N / 10 == 0) {
            return 1;
        } else {
            return 1 + countNoDigits1(N / 10);
        }
    }

    // Using while loop:
    static int countNoDigits2(int N) {
        // Handle the case where N is 0
        if (N == 0) {
            return 1;
        }

        // Handle negative numbers by taking their absolute value
        N = std::abs(N);

        int count = 0;
        while (N > 0) {
            count++;
            N /= 10;
        }

        return count;
    }

    // Optimized Approach:
    static int countNoDigits3(int N) {
        // Handle the case where N is 0
        if (N == 0) {
            return 1;
        }

        // Handle negative numbers by taking their absolute value
        N = std::abs(N);

        // Count digits using log10
        return static_cast<int>(std::log10(N)) + 1;
    }
};

int main() {
    Count_Digits cD;
    cout << cD.evenlyDivides(12) << "\n";
    cout << cD.countNoDigits1(-32781623)<< "\n";
    cout << cD.countNoDigits2(-3278162)<< "\n";
    cout << cD.countNoDigits3(-327816)<< "\n";
}