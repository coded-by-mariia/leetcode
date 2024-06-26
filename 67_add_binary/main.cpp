/***********************************************************************
 * Problem 67: Add Binary: Easy
 * 
 * Given two binary strings a and b, return their sum as a binary string
************************************************************************/

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>

std::string add_binary(const std::string&, const std::string&);

std::string add_binary(const std::string &a, const std::string &b) {
    std::string result;
    auto it_a = a.rbegin();
    auto it_b = b.rbegin();
    int carry {0};

    while (it_a != a.rend() || it_b != b.rend() || carry) { 
        int sum = carry;
        if (it_a != a.rend()) {
            sum += *it_a - '0';
            it_a++;
        }
        if (it_b != b.rend()) {
            sum += *it_b - '0';
            it_b++;
        }
        carry = sum / 2;
        result += (sum % 2) + '0';
    }
    std::reverse(result.begin(), result.end());

    return result;
}


int main() {
    std::vector<std::string> vec_a {"01", "1111"};
    std::vector<std::string> vec_b {"1", "100"};

    for (const auto &a : vec_a) {
        for (const auto &b : vec_b) {
            std::string result = add_binary(a,b);
            std::cout << std::setw(5) << std::left << a << " + "
                      << std::setw(5) << std::left << b << " = " 
                      << result << std::endl;
        }
    }

    return 0;
}

