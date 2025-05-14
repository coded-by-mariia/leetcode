/***************************************************************************************
 * Problem 189: Rotate Array: Medium
 * 
 * Given an integer array nums, rotate the array to the right by k steps, 
 * where k is non-negative.
 * 
***************************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>

void print_vector(const std::vector<int>& vec) {
    std::cout << "[ ";
    for (const auto& i : vec) {
        std::cout << i << " ";
    }
    std::cout << "]\n";
}

void rotate_vector(std::vector<int>& vec, int k) {
    int n = vec.size();
    if (n == 0) return; // handle empty vector
    k = k % n;
    
    auto reverse = [](std::vector<int>& v, int start, int end) {
        while (start < end) {
            std::swap(v[start++], v[end--]);
        }
    };
    
    reverse(vec, 0, n - 1);
    reverse(vec, 0, k - 1);
    reverse(vec, k, n - 1);
}


int main() {

    std::vector<int> original {1, 2, 3, 4, 5, 6, 7};

    std::cout << "\nOriginal Vector:\n\t";
    print_vector(original);
    std::cout << "\n";

    for (int k = 1; k <= 8; k++) {
        std::vector<int> vec = original;  // reset to original before each rotation
        rotate_vector(vec, k);
        std::cout << "Vector after rotation (k = " << k << "):\n\t";
        print_vector(vec);
    }

    return 0;
}


