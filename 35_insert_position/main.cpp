/**************************************************************************
 * Problem 35: Search Insert Position: Easy
 * 
 * Given a sorted array of distinct integers and a target value, 
 * return the index if the target is found. If not, return the index 
 * where it would be if it were inserted in order.
 * 
 * You must write an algorithm with O(log n) runtime complexity.
**************************************************************************/

#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

int search_insert(const std::vector<int> &test_vec, const int &target) {
   int left {0};
   int right = test_vec.size() - 1;

    while (left <= right) {
        int mid = (left + right) / 2;
        if (test_vec.at(mid) == target) 
            return mid;
        else if (test_vec.at(mid) < target) 
            left = mid + 1;
        else if (test_vec.at(mid) > target) 
            right = mid - 1;
    }
   return left;
}

int main() {
    std::vector<int> test_vec {1,3,5,6};
    int target1 {5}, target2 {2}, target3 {7};

    std::cout << "[ ";
    for (const auto &i : test_vec) {
        std::cout << i << " ";
    }
    std::cout << "], target " << target1 << " : " << search_insert(test_vec, target1) << std::endl;

     std::cout << "[ ";
    for (const auto &i : test_vec) {
        std::cout << i << " ";
    }
    std::cout << "], target " << target2 << " : " << search_insert(test_vec, target2) << std::endl;

     std::cout << "[ ";
    for (const auto &i : test_vec) {
        std::cout << i << " ";
    }
    std::cout << "], target " << target3<< " : " << search_insert(test_vec, target3) << std::endl; 


    return 0;
}