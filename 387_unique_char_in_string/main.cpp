/****************************************************************************
 * Problem 387: First unique character in a string: Easy
 * 
 * Given a string s, find the first non-repeating character in 
 * it and return its index. If it does not exist, return -1.
 * 
****************************************************************************/

#include <iostream>
#include <string>
#include <unordered_map>

int first_unique_char(std::string& s) {
    std::unordered_map<char, int> char_counter;

    for (auto& ch : s) {
        char_counter[ch]++;
    }

    for (size_t i = 0; i < s.length(); i++) {
        if (char_counter[s[i]] == 1) 
            return i;
    }

    return -1;
}

int main() {
    std::string s1 = "leetcode";
    std::string s2 = "loveleetcode";
    std::string s3 = "aabb";

    std::cout << "First unique character index in \"" << s1 << "\": " 
              << first_unique_char(s1) << std::endl;

    std::cout << "First unique character index in \"" << s2 << "\": " 
              << first_unique_char(s2) << std::endl;

    std::cout << "First unique character index in \"" << s3 << "\": " 
              << first_unique_char(s3) << std::endl;

    return 0;
}