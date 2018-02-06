// File: binary_search.cpp
// Author: Phi Luu
// Created: February 05, 2018
//
// Algorithmic Toolbox - Week 4 - Divide-and-Conquer Algorithms
// See ./week4_divide_and_conquer.pdf for details

#include <algorithm>
#include <iostream>
#include <vector>

int BinarySearch(std::vector<int> array, int value);

int main(void) {
    int n, k;

    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) std::cin >> a[i];

    typedef struct intindex {
        int value;
        int index;  // original index before sorting

        // enables sorting by value
        bool operator<(const intindex& rhs) { return value < rhs.value; }
    } intindex;

    std::cin >> k;
    std::vector<intindex> b(k);
    for (int i = 0; i < k; i++) {
        std::cin >> b[i].value;
        b[i].index = i;
    }

    // sort b ascending for later use
    std::sort(b.begin(), b.end());

    std::vector<int> indexlist(k);

    // search for each element of b in a
    for (int i = 0; i < b.size(); i++) {
        // yield -1 immediately if the value is out of a's bound
        if ((b[i].value < a.front()) || (b[i].value > a.back())) {
            indexlist[b[i].index] = -1;
        } else {
            // only do binary search if the element in b has not been searched yet
            if ((i == 0) || (b[i].value != b[i - 1].value)) {
                indexlist[b[i].index] = BinarySearch(a, b[i].value);
            }
            // otherwise, copy the result from the previous search
            else {
                indexlist[b[i].index] = indexlist[b[i - 1].index];
            }
        }
    }

    // output result
    for (auto& index : indexlist) std::cout << index << " ";
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
