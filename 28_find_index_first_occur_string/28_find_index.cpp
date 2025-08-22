/// ===============================================================
/// Problem # : 28
/// Title     : Find the Index of the First Occurrence in a String
/// Difficulty: Easy
///
/// Description:
/// Given two strings needle and haystack, return the index of the first
/// occurrence of needle in haystack, or -1 if needle is not part of haystack.
///
/// Constraints:
/// - 1 <= haystack.length, needle.length <= 10^4
/// - haystack and needle consist of only lowercase English characters.
///
/// Approaches:
/// 1) Sliding Window:
///    Compare substrings of haystack with needle at each position.
///    Time Complexity: O(n*m). 
///    Space Complexity: O(1).
///
/// 2) KMP (Knuth–Morris–Pratt):
///    Preprocess needle to build LPS (longest prefix-suffix) array.
///    Use it to skip redundant comparisons.
///    Time Complexity: O(n+m).
///    Space Complexity: O(m).
///
/// ===============================================================

#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    /// Sliding Window Approach
    int strStrSlidingWindow(const std::string haystack, const std::string needle) {
        int n = haystack.size();
        int m = needle.size();

        if (m == 0)
            return -1;
        
        for (int i = 0; i <= n - m; i++) {
            if (haystack.substr(i,m) == needle) 
                return i;
        }
        
        return -1;
    }

    /// build LPS array for needle
    std::vector<int> buildLPS(const std::string& needle) {        
        std::vector<int> lps (needle.size(), 0);
        for (size_t pre = 0, suf = 1; suf < needle.size();) {
            if (needle[pre] == needle[suf]) {
                lps[suf++] = ++pre;
            } else if (pre != 0) {
                pre = lps[pre - 1];
            } else {
                lps[suf++] = 0;
            }
        }

        return lps;
    }

    /// KMP Approach
    int strStrKMP(std::string haystack, std::string needle) {    
        int n = haystack.size();
        int m = needle.size();

        if (needle.empty() || m > n) return -1; 
        
        int i = 0; // for haystack
        int j = 0; // for needle

         std::vector<int> lps = buildLPS(needle);

        while (i < n) {
            if (haystack[i] == needle[j]) {
                i++;
                j++;
            }
            if (j == m) {
                return i - j; // match found
            } else if (haystack[i] != needle[j]) {
                if (j!= 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }

        return -1; // match not found        
    }
};

/// Driver code for local testing
int main() {
    Solution sol;

    // -------------------------------------------------------------------------------------------
    std::string haystack_1 = "sadbutsad";
    std::string needle_1   = "sad";
    // expected output 0

    std::cout << "\n=== Case 1: " << haystack_1 << ", " << needle_1 << " ===\n"; // expected 0
    std::cout << "\tSliding Window: " << sol.strStrSlidingWindow(haystack_1, needle_1) << std::endl;
    std::cout << "\tKMP           : " << sol.strStrKMP(haystack_1, needle_1) << std::endl;

    // -------------------------------------------------------------------------------------------
    std::string haystack_2 = "leetcode";
    std::string needle_2   = "leeto";
    // expected output -1
    
    std::cout << "\n=== Case 2: " << haystack_2 << ", " << needle_2 << " ===\n";
    std::cout << "\tSliding Window: " << sol.strStrSlidingWindow(haystack_2, needle_2) << std::endl;
    std::cout << "\tKMP           : " << sol.strStrKMP(haystack_2, needle_2) << std::endl;

    // -------------------------------------------------------------------------------------------
    std::string haystack_3 = "abcabcabd";
    std::string needle_3   = "abcabd";
    // expected output 3

    std::cout << "\n=== Case 3: " << haystack_3 << ", " << needle_3 << " ===\n"; 
    std::cout << "\tSliding Window: " << sol.strStrSlidingWindow(haystack_3, needle_3) << std::endl;
    std::cout << "\tKMP           : " << sol.strStrKMP(haystack_3, needle_3) << std::endl;

    // -------------------------------------------------------------------------------------------
    std::string haystack_4 = "mississippi";
    std::string needle_4   = "issip";
    // expected output 4

    std::cout << "\n=== Case 4: " << haystack_4 << ", " << needle_4 << " ===\n"; 
    std::cout << "\tSliding Window: " << sol.strStrSlidingWindow(haystack_4, needle_4) << std::endl;
    std::cout << "\tKMP           : " << sol.strStrKMP(haystack_4, needle_4) << std::endl;


    return 0;
}