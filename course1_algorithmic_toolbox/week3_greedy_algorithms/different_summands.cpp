// File: different_summands.cpp
// Author: Phi Luu
// Created: February 05, 2018
//
// Algorithmic Toolbox - Week 03 - Greedy Algorithms
// See ./week3_greedy_algorithms.pdf for details

#include <iostream>
#include <vector>

int main(void) {
    int n;

    std::cin >> n;

    std::vector<int> summand;
    int candies = n;
    // always start with 1 and work the way up to maximize number of summands
    int i = 1;

    // only add to summand if the subtraction is greater than the greatest summands
    while ((candies - i > i) || (candies == i)) {
        summand.push_back(i);  // record the summand
        candies -= i;  // update the remaining candies
        i++;  // try with the next integer
    }

    // if the candies is unable to be zero due to repeating summands, take the rest
    if (candies > 0) summand.push_back(candies);

    // output the maximum number of summands the list of them
    std::cout << summand.size() << std::endl;
    for (auto& num : summand) std::cout << num << " ";
    std::cout << std::endl;

    return 0;
}
