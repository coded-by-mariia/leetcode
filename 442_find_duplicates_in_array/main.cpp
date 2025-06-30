/********************************************************************************
 * Problem 442: Find all duplicates in an Array: Medium
 * 
 * Given an integer array nums of length n where all the integers of nums are 
 * in the range [1, n] and each integer appears at most twice, return an array 
 * of all the integers that appears twice.
 * 
 * You must write an algorithm that runs in O(n) time and uses only constant 
 * auxiliary space, excluding the space needed to store the output.
 * 
********************************************************************************/

#include <iostream>
#include <cmath>
#include <vector>

void print_vector(const std::vector<int>& nums) {
    std::cout << "[ ";
    for (const auto& x : nums) {
        std::cout << x << " ";
    }
    std::cout << "]\n";
}

std::vector<int> find_duplicates(std::vector<int>& nums) {
    std::vector<int> res;

    for (size_t i = 0; i < nums.size(); i++) {
        int idx = abs(nums[i]) - 1;
        if (nums[idx] < 0) {
            res.push_back(nums[i]);
        } else {
            nums[idx] = -nums[idx];
        }
    }

    return res;
}

int main() {
    std::vector<std::vector<int>> test_vecs {
        {1,2,3,4,3,2,1},
        {1,2,3,4,5},
        {},
        {1}
    };

    for (auto& test_vec : test_vecs) {
        std::cout << "\nOriginal vector:  ";
        print_vector(test_vec);
        
        std::vector<int> res = find_duplicates(test_vec);
        
        std::cout << "After flipping:   ";
        print_vector(test_vec);
        
        std::cout << "Result:           ";
        print_vector(res);
    }

    return 0;
}