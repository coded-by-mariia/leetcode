/***********************************************************************
 * Task 1 "Two Sum"
 * 
 * Given an array of integers nums and an integer target, return indices 
 * of the two numbers such that they add up to target.
 * 
 * You may assume that each input would have exactly one solution, and 
 * you may not use the same element twice.
 * 
 * You can return the answer in any order.
*************************************************************************/

#include <iostream>
#include <map>

std::vector<int> solution(const std::vector<int> &nums, const int &target) {
    std::unordered_map<int,int> num_map;

    for (int i {0}; i < nums.size(); i++) {
        if (num_map.find(target - nums[i]) != num_map.end()) {
            return {num_map[target - nums[i]], i};
        }
        num_map[nums.at(i)] = i;
    }
    return {};
}


int main() {
    int target = 10;
    std::vector<int> nums {1,2,8,5,6};
    std::vector<int> result = solution(nums, target);
    std::cout << "\nThe result indexes are: [" << result.at(0) 
              << ", " << result.at(1) << "]" << std::endl;

    return 0;
}