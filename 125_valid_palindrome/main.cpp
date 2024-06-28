/************************************************************************** 
 * Problem 125: Valid Palindrome: Easy
 * A phrase is a palindrome if, after converting all uppercase letters into 
 * lowercase letters and removing all non-alphanumeric characters, it reads 
 * the same forward and backward. Alphanumeric characters include letters 
 * and numbers.
 * 
 * Given a string s, return true if it is a palindrome, or false otherwise.
**************************************************************************/

#include <iostream>
#include <iomanip>
#include <cctype>
#include <string>
#include <deque>
#include <algorithm>

bool is_polindrome(const std::string&);

bool is_polindrome(const std::string &str) {
    std::deque<char> d;

    for (const auto &ch : str) {
        d.push_back(std::toupper(ch));
    }

    while (d.size() > 1) {
        if (d.front() != d.back()) {
            return false;
        }
        d.pop_back();
        d.pop_front();
    }

    return true;
}

int main() {
    std::cout << std::boolalpha<< std::endl;

    std::vector<std::string> test_vec;
    test_vec.push_back("a");
    test_vec.push_back("Aba");
    test_vec.push_back("155");
    test_vec.push_back("12321");
    test_vec.push_back("aa1AA");

    for (const auto &test_str : test_vec) {
        std::cout << std::setw(15) << std::left << test_str
              << " : " << is_polindrome(test_str) 
              << std::endl;
    }

    return 0;
}




