/// ===============================================================
/// Problem # : 27
/// Title     : Remove Elements
/// Difficulty: Easy
///
/// Description:
/// Given an integer array nums and an integer val, remove all occurrences 
/// of val in nums IN-PLACE. The order of the elements may be changed. Then 
/// return the number of elements in nums which are not equal to val.
///
/// Constraints:
/// - 0 <= nums.length <= 100
/// - 0 <= nums[i] <= 50
/// - 0 <= val <= 100
///
/// Approach:
/// Variation of two-pointer technique: two-iterator technique, where  
/// one iterator scans the vector and the other tracks the write position,  
/// swapping elements in place to move non-target values forward.
///
/// Time Complexity: O(n)
/// Space Complexity: O(1)
/// ===============================================================

#include <iostream>
#include <vector>

class Solution {
public:
    size_t remove_in_place(std::vector<int>& test_vec, const int target) {
    
        auto it_1 = test_vec.begin();
        auto it_2 = test_vec.begin();

        while (it_1 != test_vec.end()) {
            if (*it_1 != target) {
                std::swap(*it_1, *it_2);
                it_2++;
            }
            it_1++;
        }
    
        return static_cast<size_t>(it_2 - test_vec.begin());
    }
};

/// Driver code for local testing
int main() {
    Solution sol;
    std::vector<std::vector<int>> test_vec_vec {
        {2,3,3,2},
        {3,1,3},
        {0,1,3,3,2,0,4,3},
        {0},
        {3}
    };
    int target {3};

    for (auto& test_vec : test_vec_vec) {
        std::cout << std::endl << std::string(25,'=') << std::endl;
        std::cout << "\nUnmodified vector: [ ";
    for (const auto& i : test_vec) {
        std::cout << i << " ";
    }
    std::cout << "]" << std::endl;
    std::cout << "Target: " << target << std::endl;

    size_t k = sol.remove_in_place(test_vec, target);

    std::cout << "\nNumber of non-target values: " << k << std::endl;
    std::cout << "Modified vector: [ ";
    for (size_t i {0}; i < test_vec.size(); i++) {
        std::cout << test_vec.at(i) << " ";
    }
    std::cout << "]" << std::endl;
    }

    return 0;
}