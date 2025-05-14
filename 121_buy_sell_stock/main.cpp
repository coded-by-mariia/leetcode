/****************************************************************************************
 * Problem 121: Best Time to Buy and Sell Stock: Easy
 * 
 * You are given an array prices where prices[i] is the price of a given stock on the ith day.
 * You want to maximize your profit by choosing a single day to buy one stock and 
 * choosing a different day in the future to sell that stock.
 * 
 * Return the maximum profit you can achieve from this transaction. 
 * If you cannot achieve any profit, return 0.
****************************************************************************************/

#include <iostream>
#include <vector>

int max_profit(const std::vector<int>& prices) {
    if (prices.empty()) return 0;

    int max_profit {0};
    int min_price = prices[0];

    for (size_t i {1}; i < prices.size(); i++) {
        if (prices[i] < min_price) {
            min_price = prices[i];
        }
        int profit = prices[i] - min_price;
        if (profit > max_profit) {
            max_profit = profit;
        }
    }

    return max_profit;
}


int main() {
    std::vector<std::vector<int>> test_cases = {
        {7, 1, 5, 3, 6, 4},
        {7, 6, 4, 3, 1},
        {}
    };

    for (const auto& prices : test_cases) {
        std::cout << "[ ";
        for (size_t i {0}; i < prices.size(); i++) {
            std::cout << prices[i] << " ";
        }
        std::cout << "] : profit " << max_profit(prices) << std::endl;
    }

    return 0;
}