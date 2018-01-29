// File: fibonacci_sum.cpp
// Author: Phi Luu
// Created: January 28, 2018
//
// Algorithmic Toolbox - Week 2 - Last Digit of the Sum of Fibonacci Numbers
// See ./week2_algorithmic_warmup.pdf for details

#include <iostream>
#include <vector>

int main(void) {
    long long n;

    std::cin >> n;

    // sum of all n fibonacci mod 10 = sum of each mod 10 fib
    // = sum of all digits of a mod10 pisano period
    // len(pisano period of 10) = 60
    int pisano[60];
    int sum = 0;
    pisano[0] = 0;
    pisano[1] = 1;

    // calculate and store the pisano period
    for (int i = 2; i < 60; i++) {
        pisano[i] = (pisano[i - 2] + pisano[i - 1]) % 10;
    }

    // calculate the sum
    for (int i = 0; i < (n + 1) % 60; i++) {
        sum = (sum + pisano[i]) % 10;
    }

    std::cout << sum << std::endl;


    return 0;
}
