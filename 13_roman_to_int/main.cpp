/***********************************************************
 * Problem 13: Roman To Integer: Easy
 * 
 * Roman numerals are represented by seven different symbols: 
 * I (1), V (5), X (10), L (50), C (100), D (500) and M (1000).
 * 
 * There are six instances where subtraction is used:
 *      I can be placed before V (5) and X (10) to make 4 and 9. 
 *      X can be placed before L (50) and C (100) to make 40 and 90. 
 *      C can be placed before D (500) and M (1000) to make 400 and 900.
 *      Given a roman numeral, convert it to an integer.
***********************************************************/

#include <map>
#include <iostream>

void vector_solution(const std::vector<std::string> &);
void solution(const std::string &);

void vector_solution(const std::vector<std::string> &roman_nums) {
    for (const auto &num : roman_nums) {
        solution(num);
    }
}

void solution(const std::string &roman) {
    std::unordered_map<char,int> dict = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };
    int total {0};

    for (int i {0}; i < roman.size(); i++) {
        if (i < (roman.size() - 1) && dict[roman.at(i)] < dict[roman.at(i+1)]) {
            total -= dict[roman.at(i)];
        } else {
            total += dict[roman.at(i)];
        }
    }

    std::cout << roman << " : " << total << std::endl;
}

int main() {
    std::vector<std::string> roman_nums {"III", "IV", "IX", "X", "XXVII", "MMDLV"};
    vector_solution(roman_nums);
    return 0;
}