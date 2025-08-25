/// ===============================================================
/// Problem # : 459
/// Title     : Repeated Substring Pattern
/// Difficulty: Easy
///
/// Description:
/// Given a string s, check if it can be constructed by taking a substring 
/// of it and appending multiple copies of the substring together.
///
/// Constraints:
/// - 1 <= s.length <= 104
/// - s consists of lowercase English letters.
///
/// Approach:
/// Using LPS array, finds the length of the longest repeated substring
/// and checks if the string length is divisible by the remaining 
/// substring length to determine repetition.
///
/// Time Complexity: O(n)
/// Space Complexity: O(n)
/// ===============================================================

#include <iostream>
#include <string>
#include <vector>

class Solution {
public:

    bool repeatedSubstringPattern(std::string s) {
        if (s.length() < 2) return false;
        
        int len = buildLPS(s);
        int n = s.length();

        if (len > 0 && n % (n - len) == 0) 
            return true;
        
        return false;
    }

    int buildLPS(const std::string& str) {
        std::vector<int> lps (str.length(), 0);
        for (size_t pre = 0, suf = 1; suf < str.length(); ) {
            if (str[pre] == str[suf]) {
                lps[suf++] = ++pre;
            } else if (pre != 0) {
                pre = lps[pre - 1];
            } else {
                lps[suf++] = 0;
            }
        }
        return lps[str.length() - 1];
    }
};

/// Driver code for local testing
int main() {
    std::cout << std::boolalpha;
    
    Solution sol;

    std::vector<std::string> test_strings {
        "a",            // false
        "ab",           // false
        "aa",           // true
        "aba",          // false
        "abab",         // true
        "abcabcabcabc"  // true
    };

    for (const auto& str : test_strings) {
        std::cout << str << " : " << sol.repeatedSubstringPattern(str) << std::endl;
    }

    return 0;
}