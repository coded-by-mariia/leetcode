/***************************************************************************************
 * Problem 349: Intersection of Two Arrays: Easy
 * 
 * Given two integer arrays nums1 and nums2, return an array of their intersection.
 * Each element in the result must be unique and you may return the result in any order.
 * 
***************************************************************************************/
#include <iostream>
#include <vector>
#include <unordered_set>

std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2) {
    std::unordered_set<int> set1 (nums1.begin(), nums1.end());
    std::unordered_set<int> result;
    
    for (const auto& y : nums2) {
        if (set1.count(y)) {
            result.insert(y);
        }
    }
    
    return std::vector<int>(result.begin(), result.end());
}

void print_vector(const std::vector<int>& nums) {
    std::cout << "[ ";
    for (const auto& x : nums) {
        std::cout << x << " ";
    }
    std::cout << "]\n";
}

int main() {
    std::vector<int> vec1 {1,2,2,1};
    std::vector<int> vec2 {2};
    auto result1 = intersection(vec1, vec2);

    std::cout << "\nVec1: ";
    print_vector(vec1);

    std::cout << "Vec2: ";
    print_vector(vec2);

    std::cout << "Intersection: ";
    print_vector(result1);

    std::cout << std::endl;

    std::vector<int> vec3 {1,2,2,1};
    std::vector<int> vec4 {5,7,8};
    auto result2 = intersection(vec3, vec4);

    std::cout << "Vec3: ";
    print_vector(vec3);

    std::cout << "Vec4: ";
    print_vector(vec4);

    std::cout << "Intersection: ";
    print_vector(result2);

    return 0;
}