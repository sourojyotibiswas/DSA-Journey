// https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/description/
#include <iostream>
#include <string>
#include <algorithm>
using std::min;
using std::string;
using std::cout;
using std::cin;

/**
    Time complexity: O(n^2)
    Space complexity: O(1)
 */

class Solution {
public:
    int numberOfSubstrings(string s) {
        int count = 0;
        for(int i=0; i<s.size(); i++){
            int hash[3] = {0};
            for(int j=i; j<s.size(); j++){
                hash[s[j]-'a'] = 1;
                if(hash[0]+hash[1]+hash[2] == 3){
                    // count += 1;
                    count += (s.size()-j);
                    break;
                }
            }
        }
        return count;
    }
};

// Optimized solution
class Solution2 {
public:
    int numberOfSubstrings(string s) {
        int count = 0;
        int last_seen[3] = {-1, -1, -1};
        for (int i = 0; i < s.size(); i++) {
            last_seen[s[i] - 'a'] = i;
            if (last_seen[0] != -1 && last_seen[1] != -1 &&
                last_seen[2] != -1) {
                // std::min initializer list overload [from c++11 >]
                count += (1 + min({last_seen[0], last_seen[1], last_seen[2]}));
            }
        }
        return count;
    }
};

int main(){
    string s;
    cin >> s;
    Solution2 sol;
    cout << sol.numberOfSubstrings(s) << '\n';
    return 0;
}