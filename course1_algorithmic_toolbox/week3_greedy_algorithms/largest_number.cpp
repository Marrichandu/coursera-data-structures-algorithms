// File: largest_number.cpp
// Author: Phi Luu
// Created: February 05, 2018
//
// Algorithmic Toolbox - Week 03 - Greedy Algorithms
// See ./week3_greedy_algorithms.pdf for details

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

bool XBeforeY(std::string x, std::string y);

int main(void) {
    int n, num;

    std::cin >> n;

    std::vector<std::string> digits(n);

    for (int i = 0; i < n; i++) {
        std::cin >> num;
        digits[i] = std::to_string(num);
    }

    std::sort(digits.begin(), digits.end(), XBeforeY);

    for (auto& digitgroup : digits) std::cout << digitgroup;

    std::cout << std::endl;

    return 0;
}

// Concatenates two digit-only strings together.
// If x + y > y + x, then x should be before y to maximize integer value -> true
// Otherwise, returns false.
bool XBeforeY(std::string x, std::string y) { return x + y > y + x; }
