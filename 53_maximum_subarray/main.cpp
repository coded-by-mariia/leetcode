/*******************************************************************************************
 * Problem 53: Maximum Subarray: Medium
 * 
 * Given an integer array nums, find the subarray with the largest sum, and return its sum
 * 
*******************************************************************************************/

#include <iostream>
#include <vector>

int max_subarray_sum(std::vector<int>& vec) {
    if (vec.empty()) return 0;
    int max_global = vec[0];
    int max_current = vec[0];

    for (size_t i {1}; i < vec.size(); i++) {
        max_current = std::max(vec[i], max_current + vec[i]);
        if (max_current > max_global) {
            max_global = max_current;
        }
    }
   
    return max_global;
}

int main() {
    std::vector<std::vector<int>> test_cases { 
        {-2,1,-3,4,-1,2,1,-5,4},
        {5,4,-1,7,8},
        {1},
        {}
    };
    
    for (auto& vec : test_cases) {
        std::cout << "\nVector: [ ";
        for (auto& i : vec) {
            std::cout << i << " ";
        }
        std::cout << "]\n";
        std::cout << "Max Subarray Sum: " << max_subarray_sum(vec) << "\n";
    }
   

    return 0;
}