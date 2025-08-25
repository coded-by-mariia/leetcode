/// ===============================================================
/// Problem # : 1
/// Title     : Two Sum
/// Difficulty: Easy
///
/// Description:
/// Given an array of integers nums and an integer target, return indices 
/// of the two numbers such that they add up to target.
///
/// Constraints:
/// - 2 <= nums.length <= 10^4
/// - -10^9 <= nums[i] <= 10^9
/// - -10^9 <= target <= 10^9
/// - Only one valid answer exists.
///
/// Approach:
/// Instead of using the naive two-pointer approach, which would require O(n^2) time, 
/// this solution leverages an unordered_map to track previously seen numbers 
/// at the cost of O(n) extra space.
///
/// Time Complexity: O(n)
/// Space Complexity: O(n)
/// ===============================================================

#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> twoSum(const std::vector<int> &nums, int target) {
        std::unordered_map<int,int> num_map;

        for (size_t i = 0; i < nums.size(); i++) {
            if (num_map.find(target - nums[i]) != num_map.end()) {
                return {num_map[target - nums[i]], static_cast<int>(i)};
            }
             num_map[nums[i]] = static_cast<int>(i);
        }
        return {};
    }
};

/// Driver code for local testing
int main() {
    Solution sol;
    int target = 10;
    std::vector<int> nums {1,2,8,5,6};
    std::vector<int> result = sol.twoSum(nums, target);
    std::cout << "\nThe result indexes are: [" << result.at(0) 
              << ", " << result.at(1) << "]" << std::endl;

    return 0;
}