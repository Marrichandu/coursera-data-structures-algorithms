// File: BinarySearch.cpp
// Author: Phi Luu
// Created: February 05, 2018
//
// Algorithmic Toolbox - Week 04 - Divide-and-Conquer Algorithms
// See ./week4_divide_and_conquer.pdf for details

#include <iostream>
#include <vector>

int BinarySearch(const std::vector<int>& array, int value);

int main(void) {
    int n, k;

    std::cin >> n;
    std::vector<int> a(n);
    for (size_t i = 0; i < a.size(); i++) std::cin >> a[i];

    std::cin >> k;
    std::vector<int> b(k);
    for (int i = 0; i < k; i++) std::cin >> b[i];

    // for each element in b, output the index of b[i] in a
    for (int i = 0; i < k; i++) std::cout << BinarySearch(a, b[i]) << " ";

    std::cout << std::endl;

    return 0;
}

// Searches for an element with the given value in an array.
// Returns the index of that element or returns if there is no such element.
int BinarySearch(const std::vector<int>& array, int value) {
    int left = 0, right = (int)array.size();

    // only do the search if the value is within the range of min and max
    if ((value >= array[left]) && (value <= array[right - 1])) {
        while (left < right) {
            int mid = (left + right) / 2;

            if (array[mid] == value) {
                return mid;  // return the index and exit if found
            } else if (array[mid] > value) {
                right = mid;  // search left half if the value > array[midpoint]
            } else {
                left = mid + 1;  // search right half
            }
        }
    }

    return -1;
}
