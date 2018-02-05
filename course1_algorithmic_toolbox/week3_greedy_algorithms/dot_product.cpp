// File: dot_product.cpp
// Author: Phi Luu
// Created: February 04, 2018
//
// Algorithmic Toolbox - Week 03 - Greedy Algorithms
// See ./week3_greedy_algorithms.pdf for details

#include <algorithm>
#include <iostream>
#include <vector>

int main(void) {
    int n;

    std::cin >> n;

    std::vector<int> profit(n), click(n);

    for (int i = 0; i < n; i++) std::cin >> profit[i];
    for (int i = 0; i < n; i++) std::cin >> click[i];

    // sort the ads from max profit to min profit
    std::sort(profit.rbegin(), profit.rend());
    // sort the slots from max click to min click
    std::sort(click.rbegin(), click.rend());

    // multiply corresponding profit and click to get the max possible revenue
    long long maxrevenue = 0;
    for (int i = 0; i < n; i++) maxrevenue += (long long)profit[i] * click[i];

    std::cout << maxrevenue << std::endl;

    return 0;
}
