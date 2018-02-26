// File: points_and_segments.cpp
// Author: Phi Luu
// Created: February 05, 2018
//
// Algorithmic Toolbox - Week 4 - Divide-and-Conquer Algorithms
// See ./week4_divide_and_conquer.pdf for details

#include <algorithm>
#include <iostream>

int CountSegments(int point, int left[], int right[], int s);

int main(void) {
    int s, p;

    std::cin >> s >> p;

    int left[s], right[s];
    for (int i = 0; i < s; i++) std::cin >> left[i] >> right[i];

    int x[p];
    for (int i = 0; i < p; i++) std::cin >> x[i];

    std::sort(left, left + s);
    std::sort(right, right + s);

    for (int i = 0; i < p; i++) {
        std::cout << CountSegments(x[i], left, right, s) << ' ';
    }
    std::cout << std::endl;

    return 0;
}

int CountSegments(int point, int left[], int right[], int s) {
    if ((point < left[0]) || (point > right[s - 1])) return 0;

    int rightindex = s;

    // find the index of the first segment that has greater left-end than point
    if (point < left[s - 1]) {
        int low = 0, high = s;
        while (low < high) {
            int mid = (low + high) / 2;

            if (point >= left[mid]) {
                low = mid + 1;
            } else {
                rightindex = mid;
                high = mid;
            }
        }
    }

    int leftindex = 0;

    // find the index of the first segment that has smaller right-end than point
    if (point > right[0]) {
        int low = 0, high = s;
        while (low < high) {
            int mid = (low + high) / 2;

            if (point <= right[mid]) {
                high = mid;
            } else {
                leftindex = mid + 1;
                low = mid + 1;
            }
        }
    }

    return rightindex - leftindex;
}
