/***************************************************************
 * Problem 9: Polindrome Number: Easy
 * Non-STL solution
 * 
 * Given an integer x, return true if x is a palindrome, 
 * and false otherwise.
****************************************************************/

#include <iostream>
#include <vector>

bool is_polindrome(int x) {
    if (x < 0) {
        return false;
    }

    int original = x;
    long reversed = 0;

    while (x > 0) {
        reversed = reversed * 10 + x % 10;
        x /= 10;
    }
    return reversed == original;  
}


int main() {
    std::cout << std::boolalpha;
    std::vector<int> nums {0, 10, 121, 155, 123321, -55};
    for (const auto &num : nums) {
        std::cout << num << " : " << is_polindrome(num) << std::endl; 
    }
    return 0;
}