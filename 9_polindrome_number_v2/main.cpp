/***************************************************************
 * Problem 9: Polindrome Number: Easy
 * STL solution
 * 
 * Given an integer x, return true if x is a palindrome, 
 * and false otherwise.
****************************************************************/

#include <iostream>
#include <iomanip>
#include <deque>
#include <string>

bool is_polindrome(const int&);

bool is_polindrome(const int &number) {
    std::deque<int> d;
    std::string str = std::to_string(number);
    for (const auto &dig : str) {
        d.push_back(dig);
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
    std::cout << std::boolalpha << std::endl;

    std::vector<int> test_vec;
    test_vec.push_back(1);
    test_vec.push_back(90);
    test_vec.push_back(1234321);
    test_vec.push_back(12312);
    test_vec.push_back(-10);
    test_vec.push_back(-101);

    for (const int &test_num : test_vec) {
        std::cout << std::setw(10) << std::left << test_num
              << " : " << is_polindrome(test_num) 
              << std::endl;
    }
    
    return 0;
}