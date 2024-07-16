/************************************************************************************
 * Problem 202: Happy Number: Easy
 * 
 * A happy number is a number defined by the following process:
 *      1. Starting with any positive integer, replace the number by the sum 
 *      of the squares of its digits.
 *      2. Repeat the process until the number equals 1 (where it will stay), 
 *      or it loops endlessly in a cycle which does not include 1.
 * 
 * Those numbers for which this process ends in 1 are happy.
************************************************************************************/

/*** Quick exapmle **************
12 : 1^2 + 2^2 = 5 => not happy
19 : 1^2 + 9^2 = 1 + 81 = 82
     8^2 + 2^2 = 64 + 4 = 68
     6^2 + 8^2 = 36 + 64 = 100
     1^2 + 0^2 + 0^2 = 1 => happy
********************************/

#include <iostream>
#include <iomanip>
#include <vector>
#include <unordered_set>

int sum_of_square_of_digits(int number) {   
    int sum {0};
    while (number > 0) {
        sum += pow((number%10),2);
        number /= 10;
    }
    return sum;
}

bool is_happy(int number) {
    std::unordered_set<int> seen;
    while (number != 1 && seen.find(number) == seen.end()) {
        seen.insert(number);
        number = sum_of_square_of_digits(number);
    }   
    return number == 1;
}

int main() {
    std::cout << std::boolalpha;
    
    std::vector<int> test_vec;
    test_vec.push_back(12);
    test_vec.push_back(19);
    test_vec.push_back(234);
    test_vec.push_back(5);

    std::cout << std::setw(10) << std::left << "\nnumber" 
              << std::setw(15) << std::left << "sum of dig" 
              << "is happy?" << std::endl;
    for (const auto &test_number : test_vec) {    
        std::cout << std::setw(10) << std::left << test_number 
                  << std::setw(15) << std::left << sum_of_square_of_digits(test_number) 
                  << is_happy(test_number) << std::endl;
    }
    
    return 0;
}