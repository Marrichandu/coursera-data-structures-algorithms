// File: fibonacci.cpp
// Author: Phi Luu
// Created: January 28, 2018
//
// Algorithmic Toolbox - Week 2 - Fibonacci Number
// See ./week2_algorithmic_warmup.pdf for details

#include <iostream>

int main(void) {
    int n, fminus1 = 1, fminus2 = 0, f;

    std::cin >> n;

    if ((n == 0) || (n == 1)) {
        std::cout << n << std::endl;
    } else {
        for (int i = 2; i <= n; i++) {
            // fibonacci number = sum of two previous ones
            f = fminus1 + fminus2;
            // set fminus1 and fminus2 of the next fib number
            fminus2 = fminus1;
            fminus1 = f;
        }
        std::cout << f << std::endl;
    }

    return 0;
}
