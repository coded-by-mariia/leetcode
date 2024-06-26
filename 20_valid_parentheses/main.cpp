/************************************************************************************
 * Problem 20: Valid Parentheses: Easy
 * 
 * Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', 
 * determine if the input string is valid.
 * 
 * An input string is valid if:
 *              1. Open brackets must be closed by the same type of brackets.
 *              2. Open brackets must be closed in the correct order.
 *              3. Every close bracket has a corresponding open bracket of the same type.
*************************************************************************************/

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <stack>

bool is_valid(const std::string&);

bool is_valid(const std::string &test_str) {
    std::stack<char> s;

    for (const char &ch : test_str) {
        if (ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        } else {
            if (s.empty()) return false;
            else if (ch == ')' && s.top() == '(') s.pop();
            else if (ch == '}' && s.top() == '{') s.pop();
            else if (ch == ']' && s.top() == '[') s.pop();
            else s.push(ch);
        }
    }

    return s.empty();
}

int main() {
    std::cout << std::boolalpha << std::endl;
    std::vector<std::string> test_vec;
    test_vec.push_back("()");
    test_vec.push_back("[]");
    test_vec.push_back("{}");
    test_vec.push_back("]");
    test_vec.push_back(")");
    test_vec.push_back("}");
    test_vec.push_back("[");
    test_vec.push_back("(");
    test_vec.push_back("{");
    test_vec.push_back("()[]{}");
    test_vec.push_back("()[");
    test_vec.push_back("[({})]");
    test_vec.push_back("(})");

    for (const auto &test_str : test_vec) {
        std::cout << std::setw(8) << std::left << test_str 
                  << " : " << is_valid(test_str) << std::endl;
    }

    return 0;
}