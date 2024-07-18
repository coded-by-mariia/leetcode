/******************************************************************************
 * Problem 27: Remove Elements: Easy
 * 
 * Given an integer array nums and an integer val, remove all occurrences 
 * of val in nums IN-PLACE. The order of the elements may be changed. Then 
 * return the number of elements in nums which are not equal to val.
 * 
 * Change the array nums such that the first k elements of nums contain 
 * the elements which are not equal to val. Return k.
*******************************************************************************/

#include <iostream>
#include <vector>

int remove_in_place(std::vector<int>& test_vec, const int& target) {
    
    auto it_1 = test_vec.begin();
    auto it_2 = test_vec.begin();

    while (it_1 != test_vec.end()) {
        if (*it_1 != target) {
            std::swap(*it_1, *it_2);
            it_2++;
        }
        it_1++;
    }
    
    return it_2 - test_vec.begin();
}

int main() {

    std::vector<std::vector<int>> test_vec_vec;
    std::vector<int> test_vec_1 {2,3,3,2};
    std::vector<int> test_vec_2 {3,1,3};
    std::vector<int> test_vec_3 {0,1,3,3,2,0,4,3};
    test_vec_vec.emplace_back(test_vec_1);
    test_vec_vec.emplace_back(test_vec_2);
    test_vec_vec.emplace_back(test_vec_3);

    int target {3};

    for (auto& test_vec : test_vec_vec) {
        std::cout << std::endl << std::string(25,'=') << std::endl;
        std::cout << "\nUnmodified vector: [ ";
    for (const auto& i : test_vec) {
        std::cout << i << " ";
    }
    std::cout << "]" << std::endl;
    std::cout << "Target: " << target << std::endl;

    int k = remove_in_place(test_vec, target);

    std::cout << "\nNumber of non-target values: " << k << std::endl;
    std::cout << "Modified vector: [ ";
    for (size_t i {0}; i < test_vec.size(); i++) {
        std::cout << test_vec.at(i) << " ";
    }
    std::cout << "]" << std::endl;
    }

    return 0;
}
