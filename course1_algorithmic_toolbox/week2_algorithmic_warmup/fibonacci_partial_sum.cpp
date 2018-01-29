// File: fibonacci_partial_sum.cpp
// Author: Phi Luu
// Created: January 28, 2018
//
// Algorithmic Toolbox - Week 2 - Last Digit of the Sum of Fibonacci Numbers Again
// See ./week2_algorithmic_warmup.pdf for details

#include <iostream>
#include <vector>

int main(void) {
    std::vector<int> pisano;
    long long n, m;
    int sum = 0;

    std::cin >> m >> n;

    // Pisano period always starts with 0 1
    pisano.push_back(0);
    pisano.push_back(1);

    // only save one Pisano period
    long long i = 2;
    do {
        pisano.push_back((pisano[i - 2] + pisano[i - 1]) % 10);
        i++;
    } while ((pisano[i - 2] != 0) || (pisano[i - 1] != 1));

    // remove the extra two 0 and 1 that are used to check the period
    pisano.erase(pisano.end() - 2, pisano.end());

    // get the last digit of the partial sum of the last digits of fib numbers
    for (int i = m % 60; i <= n % 60; i++) sum = (sum + pisano[i]) % 10;

    // print the result
    std::cout << sum << std::endl;

    return 0;
}
