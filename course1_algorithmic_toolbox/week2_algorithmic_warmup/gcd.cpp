// File: gcd.cpp
// Author: Phi Luu
// Created: January 28, 2018
//
// Algorithmic Toolbox - Week 2 - Greatest Common Divisor
// See ./week2_algorithmic_warmup.pdf for details

#include <iostream>

int gcd(int a, int b);

int main(void) {
    int a, b;

    std::cin >> a >> b;
    std::cout << gcd(a, b) << std::endl;

    return 0;
}

// Finds the greatest common divisor of two integers a and b.
int gcd(int a, int b) {
    // the gcd of an integer and zero is the integer itself
    if (a == 0) return b;
    if (b == 0) return a;

    // replace the smaller with the remainder of bigger divided by smaller
    // replace the bigger with the smaller
    // then find the gcd of those two
    if (a < b) {
        return gcd(b % a, a);
    } else {
        return gcd(b, a % b);
    }
}
