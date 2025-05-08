/****************************************************************************************
 * Problem 26: Remove Duplicates from Sorted Array: Easy
 * 
 * Given an integer array nums sorted in non-decreasing order, remove 
 * the duplicates in-place such that each unique element appears only once.
 * The relative order of the elements should be kept the same. 
 * Then return the number of unique elements in nums.
 * 
 * Consider the number of unique elements of nums to be k, to get accepted, 
 * you need to do the following things:
 *      * Change the array nums such that the first k elements of nums 
 *        contain the unique elements in the order they were present in nums initially. 
 *      * The remaining elements of nums are not important as well as the size of nums.
 *      * Return k.
****************************************************************************************/

#include <iostream>
#include <vector>

size_t remove_duplicates(std::vector<int>& vec) {
    size_t k = 1;
    for (size_t i = 1; i < vec.size(); i++) {
        if (vec[i] != vec[i-1]) {
            vec[k] = vec[i];
            k++;
        }
    }
    return k;
}


int main() {
    std::vector<std::vector<int>> test_cases = {
        {1,1,2},
        {0,0,0,1,1,1,1,2,2,2,2,2,5},
        {}
    };

    // prints initial vector of vectors
    std::cout << "\nInitial vectors:\n";
    for (auto vec : test_cases) {
        std::cout << "\t[ ";
        for (size_t i {0}; i < vec.size(); i++) {
            std::cout << vec[i] << " ";
        }
        std::cout << "]\n";
    }

    // prints after moodifying
    std::cout << "After removing duplicates:\n";
    for (auto &vec : test_cases) {
        size_t unique_el = remove_duplicates(vec);

        std::cout << "\t[ ";
        for (size_t i {0}; i < vec.size(); i++) {
            std::cout << vec[i] << " ";
        }
        std::cout << "] : " << unique_el << "\n";
    }


    return 0;
}