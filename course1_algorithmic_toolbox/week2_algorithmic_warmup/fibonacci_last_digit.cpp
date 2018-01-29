// File: fibonacci_last_digit.cpp
// Author: Phi Luu
// Created: January 28, 2018
//
// Algorithmic Toolbox - Week 2 - Last Digit of a Large Fibonacci Number
// See ./week2_algorithmic_warmup.pdf for details

#include <iostream>

int main(void) {
    int n, fminus2_lastdigit = 0, fminus1_lastdigit = 1, f_lastdigit;

    std::cin >> n;

    if ((n == 0) || (n == 1)) {
        std::cout << n << std::endl;
    } else {
        for (int i = 2; i <= n; i++) {
            // use fibonacci formula
            f_lastdigit = (fminus2_lastdigit + fminus1_lastdigit) % 10;
            // set the last digits of fminus2 and fminus1 for the next fib
            fminus2_lastdigit = fminus1_lastdigit;
            fminus1_lastdigit = f_lastdigit;
        }
        std::cout << f_lastdigit << std::endl;
    }

    return 0;
}
