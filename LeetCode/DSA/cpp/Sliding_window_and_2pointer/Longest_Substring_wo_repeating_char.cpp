// https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

// Brute force approach

// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         int n = s.size();
//         int maxlen = 0;

//         for (int i = 0; i < n; i++) {
//             int hash[256] = {0}; // Initialize all characters as not seen

//             for (int j = i; j < n; j++) {
//                 if (hash[s[j]] == 1) { // If character is already seen, break
//                     break;
//                 }
//                 hash[s[j]] = 1; // Mark character as seen
//                 maxlen = max(maxlen, j - i + 1); // Update max length if necessary
//             }
//         }

//         return maxlen;
//     }
// };

// int main() {
//     Solution solution;
//     string s = "cadbzabc"; // Example input
//     cout << "Length of the longest substring without repeating characters: " 
//          << solution.lengthOfLongestSubstring(s) << endl; // Expected output: 3
//     return 0;
// }


// optimized version using array

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int hash[256]; 
        fill(begin(hash), end(hash), -1); // Initialize all elements to -1

        int n = s.size();
        int l = 0, r = 0, maxlen = 0;

        while (r < n) {
            if (hash[s[r]] != -1 && hash[s[r]] >= l) {
                l = hash[s[r]] + 1; // Move the left pointer to the right of the last occurrence
            }
            
            hash[s[r]] = r; // Update the position of the current character
            maxlen = max(maxlen, r - l + 1); // Update max length if current length is larger
            r++;
        }

        return maxlen;
    }
};

int main() {
    Solution solution;
    string s = "cadbzabc"; // Example input
    cout << "Length of the longest substring without repeating characters: " 
         << solution.lengthOfLongestSubstring(s) << endl;
    return 0;
}

// Optimized version using unordered_map

// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         unordered_map<char, int> hash;
//         int n = s.size();
//         int l = 0, maxlen = 0;

//         for (int r = 0; r < n; r++) {
//             if (hash.find(s[r]) != hash.end() && hash[s[r]] >= l) {
//                 l = hash[s[r]] + 1;  // Move left pointer right after the last occurrence
//             }
//             hash[s[r]] = r;  // Update the index of the character
//             maxlen = max(maxlen, r - l + 1);
//         }
//         return maxlen;
//     }
// };

// int main() {
//     Solution solution;
//     string s = "cadbzabc"; // Example input
//     cout << "Length of the longest substring without repeating characters: " 
//          << solution.lengthOfLongestSubstring(s) << endl; // Expected output: 3
//     return 0;
// }

/*
In this scenario, both the `unordered_map` and array-based (`hash[256]`) approaches are efficient, but each has its own advantages:

### 1. **Array Approach (`hash[256]`)** 
   - **Time Complexity**: \(O(n)\) — We process each character in the string once.
   - **Space Complexity**: \(O(1)\) — Fixed size of `256`, which is constant regardless of string size.
   - **Pros**:
     - Faster for fixed ASCII character sets, as array indexing is generally faster than hash lookups.
     - Simple and effective when we know the range of characters is small (e.g., ASCII).
   - **Cons**:
     - Limited to ASCII characters. If the input contains Unicode, this approach would not cover it.

### 2. **`unordered_map` Approach**
   - **Time Complexity**: \(O(n)\) — Similar to the array approach, it also processes each character once.
   - **Space Complexity**: \(O(min(n, m))\) — \(m\) is the character range (could be larger for Unicode); requires space proportional to unique characters in the substring.
   - **Pros**:
     - Flexible and can handle larger character sets, such as Unicode, as it dynamically stores only seen characters.
   - **Cons**:
     - Slightly slower due to hash table operations and overhead.
     - Requires more memory if the character range is large (for large alphabets, like Unicode).

### Conclusion

- **For standard ASCII strings (as in your example)**, the **array approach** (`hash[256]`) is slightly better in terms of speed and simplicity.
- **For strings with potentially large or complex character sets (e.g., Unicode)**, the **unordered_map approach** is more versatile and preferable.

In summary, if your use case is strictly ASCII-based, stick with the **array approach**. If you may need support for other character sets, go with **unordered_map** for broader compatibility.
 */