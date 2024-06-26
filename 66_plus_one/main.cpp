/***************************************************************************
 * Problem 66: Plus One: Easy
 * 
 * You are given a large integer represented as an integer array digits, 
 * where each digits[i] is the ith digit of the integer. 
 * The digits are ordered from most significant to least significant in left-to-right order. 
 * The large integer does not contain any leading 0's.
 * 
 * Increment the large integer by one and return the resulting array of digits.
******************************************************************************/


#include <iostream>
#include <vector>
#include <string>

std::vector<int> plus_one(std::vector<int> &number) {
    auto it = number.end() - 1;

    while (true) {
        if (*it == 9) {
            *it = 0;
            if (it == number.begin()) {
                number.insert(number.begin(), 1);
                break;
            }
        it--;
        } else {
            *it += 1;
            break;
        }
    }
    return number;
}

void display_vector(const std::vector<int> &vec) {
    std::cout << "\n[ ";
    for (const auto &dig : vec) {
        std::cout << dig << " ";
    }
    std::cout << "]" << std::endl;
}


int main() {
    std::vector<std::vector<int>> vec_nums;
    vec_nums.push_back({1,2,3,4});
    vec_nums.push_back({9});
    vec_nums.push_back({9,9,9,9});
    vec_nums.push_back({1,8,9});
    vec_nums.push_back({1,9,3,4});
    vec_nums.push_back({9,2,3,4});
 
    for (auto &number : vec_nums) {
        std::cout << "\nVector before incremetion: ";
        display_vector(number);
        plus_one(number);
        std::cout << "Vector after incremention: ";
        display_vector(number);
    }
   
    return 0;
}
