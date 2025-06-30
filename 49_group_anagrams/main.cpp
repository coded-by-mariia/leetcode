/*****************************************************************************
 * Problem 49: Group Anagrams: Medium
 * 
 * Given an array of strings strs, group the anagrams together.
 * You can return the answer in any order.
 * 
*****************************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <sstream>

using namespace std;

vector<vector<string>> group_anagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> anagram_groups;

    for (const auto& str : strs) {
        int count[128] = {0};

        for (auto ch : str) {
            count[(int)ch]++;
        }

        // create a unique key to a group
        stringstream key_stream;
        for (int i = 0; i < 128; i++) {
            if (count[i] > 0) {
                key_stream << i << ':' << count[i] << '|';
            } 
        }

        string key = key_stream.str(); // convert stringstream into std::string

        anagram_groups[key].push_back(str);
    }

    vector<vector<string>> result;
    for (auto& pair : anagram_groups) {
        result.push_back(move(pair.second));
    }

    return result;       
}

int main() {
    vector<string> test1 = { "eat","tea","tan","ate","nat","bat" };

    vector<vector<string>> grouped = group_anagrams(test1);

    cout << "Grouped Anagrams:\n";
    for (const auto& group : grouped) {
        cout << "\t[ ";
        for (const auto& word : group) {
            cout << "\"" << word << "\" ";
        }
        cout << "]\n";
    }


    return 0;
}