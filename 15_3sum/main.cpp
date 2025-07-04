/**********************************************************************************
 * Problem 15: 3sum: Medium
 * 
 * Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] 
 * such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
 * 
 * Notice that the solution set must not contain duplicate triplets.
 * 
**********************************************************************************/

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

std::vector<std::vector<int>> three_sum(std::vector<int>& nums) {
    std::vector<std::vector<int>> result;

    sort(nums.begin(), nums.end());

    for (size_t i = 0; i < nums.size(); i++) {
        if (i > 0 && nums[i] == nums[i-1]) {
            continue;
        }

        int left = i + 1;
        int right = nums.size() - 1;

        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];

            if (sum == 0) {
                result.push_back({nums[i], nums[left], nums[right]});

                while (left < right && nums[left] == nums[left + 1]) {
                    ++left;
                }
                while (left < right && nums[right] == nums[right - 1]) {
                    --right;
                }

                left++;
                right--;
            } else if (sum < 0) {
                left++;
            } else {
                right--;
            }
        }
    }

    return result;   
}

void print_vector(const std::vector<int>& vec) {
    std::cout << "[ ";
    for (const auto& i : vec) {
        std::cout << i << " ";
    }
    std::cout << "]\n";
}

int main() {
    std::vector<std::vector<int>> cases {
        {-1, 0, 1, 2, -1, -4},
        {0, 1, 1},
        {0, 0, 0}
    };

    for (size_t i = 0; i < cases.size(); ++i) {
        std::cout << "\nTest case " << i + 1 << ": ";
        std::cout <<"\t\t";
        print_vector(cases[i]);

        std::vector<std::vector<int>> result = three_sum(cases[i]);

        std::cout << "Triplets summing to 0:\n";
        for (const auto& triplet : result) {
            std::cout <<"  \t\t\t";
            print_vector(triplet);
        }
        std::cout << "\n----------------------\n";
    }


    return 0;
}