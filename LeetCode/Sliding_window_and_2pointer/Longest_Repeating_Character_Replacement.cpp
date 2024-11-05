// https://leetcode.com/problems/longest-repeating-character-replacement/

#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::string;

/*
Time Complexity: O(n), where n is the length of the string s. 
We iterate through the string once with the end pointer and the start pointer only moves forward.

Space Complexity: O(1). 
We use a fixed-size array of length 26 to store the frequency of characters, which does not depend on the input size.
*/
class Solution {
public:
    int characterReplacement(string s, int k) {
        int max_count = 0, start = 0, max_length = 0;
        int count[26] = {0};

        for (int end = 0; end < s.length(); ++end) {
            max_count = std::max(max_count, ++count[s[end] - 'A']);
            while (end - start + 1 - max_count > k) {
                --count[s[start] - 'A'];
                ++start;
            }
            max_length = std::max(max_length, end - start + 1);
        }

        return max_length;
    }
};

int main() {
    Solution s;
    string str;
    int k;
    cin >> str >> k;
    cout << s.characterReplacement(str, k) << "\n";
    return 0;
}