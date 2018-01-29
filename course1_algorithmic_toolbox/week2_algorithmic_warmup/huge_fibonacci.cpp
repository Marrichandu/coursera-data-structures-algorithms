// File: huge_fibonacci.cpp
// Author: Phi Luu
// Created: January 28, 2018
//
// Algorithmic Toolbox - Week 2 - Fibonacci Number Again
// See ./week2_algorithmic_warmup.pdf for details

#include <iostream>
#include <vector>

int main(void) {
    std::vector<int> pisano;
    long long n;
    int m;

    std::cin >> n >> m;

    if ((n == 0) || (n == 1)) {
        std::cout << n << std::endl;
    } else {
        // Pisano period always starts with 0 1
        pisano.push_back(0);
        pisano.push_back(1);

        // only save one Pisano period
        long long i = 2;
        do {
            pisano.push_back((pisano[i - 2] + pisano[i - 1]) % m);
            i++;
        } while ((pisano[i - 2] != 0) || (pisano[i - 1] != 1));

        // remove the extra two 0 and 1 that are used to check the period
        pisano.erase(pisano.end() - 2, pisano.end());

        // print the result
        std::cout << pisano[n % pisano.size()] << std::endl;
    }

    return 0;
}
