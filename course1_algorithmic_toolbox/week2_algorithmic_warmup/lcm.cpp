// Files: lcm.cpp
// Author: Phi Luu
// Created: January 28, 2018
//
// Algorithmic Toolbox - Week 2 - Least Common Multiple
// See ./week2_algorithmic_warmup.pdf for details

#include <iostream>

int gcd(int a, int b);
long long lcm(int a, int b);

int main(void) {
    int a, b;

    std::cin >> a >> b;
    std::cout << lcm(a, b) << std::endl;

    return 0;
}

// Returns the least common multiple of two integers.
long long lcm(int a, int b) {
    return (long long)a * (long long)b / (long long)gcd(a, b);
}

// Returns the greatest common divisor of two integers.
int gcd(int a, int b) {
    // the gcd of zero and an integer is the integer itself
    if (a == 0) return b;
    if (b == 0) return a;

    // replace the smaller with remainder of bigger divided by smaller
    // replace the bigger with the smaller
    // then find the gcd of those two
    if (a < b) {
        return gcd(b % a, a);
    } else {
        return gcd(b, a % b);
    }
}
