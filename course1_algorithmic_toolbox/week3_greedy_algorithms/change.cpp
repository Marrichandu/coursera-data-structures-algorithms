// File: change.cpp
// Author: Phi Luu
// Created: February 04, 2018
//
// Algorithmic Toolbox - Week 03: Greedy Algorithms
// See ./week3_greedy_algorithms.pdf for details

#include <iostream>

int main(void) {
    int m;

    std::cin >> m;
    
    const int NUM_DENOMINATIONS = 3;
    int remain = m, i = 0, num_coins = 0;
    int denomination[NUM_DENOMINATIONS] = { 10, 5, 1 };
    
    for (int i = 0; i < NUM_DENOMINATIONS; i++) {
        num_coins += remain / denomination[i];
        remain %= denomination[i];
    }

    std::cout << num_coins << std::endl;

    return 0;
}
