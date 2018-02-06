// File: binary_search.cpp
// Author: Phi Luu
// Created: February 05, 2018
//
// Algorithmic Toolbox - Week 4 - Divide-and-Conquer Algorithms
// See ./week4_divide_and_conquer.pdf for details

#include <iostream>
#include <vector>

int BinarySearch(std::vector<int> array, int value);

int main(void) {
    int n, k;

    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) std::cin >> a[i];

    std::cin >> k;
    std::vector<int> b(k);
    for (int i = 0; i < k; i++) std::cin >> b[i];

    // search for each element of b in a
    for (auto& num : b) std::cout << BinarySearch(a, num) << " ";

    std::cout << std::endl;

    return 0;
}

// Searches for an element in an array and returns the index of that element if
// found or returns -1 if not found.
int BinarySearch(std::vector<int> array, int value) {
    int low = 0, high = array.size();
    int position = -1;  // always assume that the element is not in the array

    while (low < high) {
        int mid = (low + high) / 2;

        if (array[mid] == value) {
            position = mid;
            break;
        } else if (array[mid] > value) {
            // search left half of the array
            high = mid;
        } else {
            // search right half of the array
            low = mid + 1;
        }
    }

    return position;
}
