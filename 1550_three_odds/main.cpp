/*************************************************************************
 * Problem 1550: Three Consecutive Odds: Easy
 * 
 * Given an integer array arr, return true if there are three consecutive 
 * odd numbers in the array. Otherwise, return false.
*************************************************************************/

#include <iostream>
#include <iomanip>
#include <vector>

bool three_cons_odds(const std::vector<int>&);

bool three_cons_odds(const std::vector<int> &test_arr) {
    if (test_arr.size() < 3) 
        return false;
    
    auto it = test_arr.begin();

    while(it != test_arr.end() - 2) {
        if (*it % 2 == 1 && *(it+1) % 2 == 1 && *(it+2) % 2 == 1) {
            return true;
        }
        it++;
    }

    return false;
}

int main() {
    std::cout << std::boolalpha << std::endl;

    std::vector<std::vector<int>> test_vec_vec;
    test_vec_vec.push_back({1,2,3,5,7,10});
    test_vec_vec.push_back({1});
    test_vec_vec.push_back({1,3,5});
    test_vec_vec.push_back({2,4,6,8,0});
    test_vec_vec.push_back({2,4,5,7});
    test_vec_vec.push_back({2,4});

    for (const auto &test_vec: test_vec_vec) {
        std::cout << "[ ";
            for (const auto &i: test_vec) {
                std::cout << i << " ";
            }
        std::cout << "] : " << three_cons_odds(test_vec) << std::endl;
    }

    return 0;
}


