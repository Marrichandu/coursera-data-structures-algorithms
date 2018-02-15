// File: majority_element.cpp
// Author: Phi Luu
// Created: February 05, 2018
//
// Algorithmic Toolbox - Week 4 - Divide-and-Conquer Algorithms
// See ./week4_divide_and_conquer.pdf for details

#include <algorithm>
#include <iostream>
#include <vector>

int CheckMajorityElementSorted(std::vector<int>& v);
int CheckMajorityElement(std::vector<int>& v);

int main(void) {
    int n;

    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) std::cin >> a[i];

    std::cout << CheckMajorityElementSorted(a) << std::endl;

    return 0;
}

int CheckMajorityElement(std::vector<int>& v) {
    int n = v.size();

    // compare two elements if the size is 2
    if (n == 2) {
        // if they are the same, then v[0] is the majority element of v
        if (v[0] == v[1]) return v[0];
        // otherwise, there is no majority element in v
        return -1;
    } else if (n == 1) {
        return v[0];
    } else if (n == 3) {
        for (int i = 0; i < n; i++) {
            int count = 1;
            for (int j = i + 1; j < n; j++) {
                if (v[j] == v[i]) count++;
                if (count > n / 2) return v[i];
            }
        }
        return -1;
    }

    // if the array is longer than 2, find the majority element in two halves
    std::vector<int> lowerhalf(v.begin(), v.begin() + n / 2);
    std::vector<int> upperhalf(v.begin() + n / 2, v.end());

    int major_lower = CheckMajorityElement(lowerhalf);
    int major_upper = CheckMajorityElement(upperhalf);

    // if lower doesn't have a majority but upper does, then major_upper = major
    if ((major_lower == -1) && (major_upper != -1)) {
        return major_upper;
    }
    // if upper doesnt' have a majority but lower does, then major_lower = major
    else if ((major_lower != -1) && (major_upper == -1)) {
        return major_lower;
    }

    // if two majority halves are the same, then they are the majority
    if (major_lower == major_upper) {
        return major_lower;
    }
    // otherwise, the original array doesn't have a majority element
    else {
        return -1;
    }
}

// Returns 1 if there is an element that occurs more than n / 2 times in an
// array of size n. Returns 0 otherwise.
int CheckMajorityElementSorted(std::vector<int>& v) {
    // this is a sneaky move. Sorting the array makes repeating elements continuous
    std::sort(v.begin(), v.end());

    int i = 0, n = v.size();

    // if any of the continuous sequence has a length more than n / 2, return 1
    while (i < n) {
        int j = i + 1;

        while (v[j] == v[i]) j++;

        // the length of the sequence = j - i
        if (j - i > n / 2) return 1;

        i = j;
    }

    // otherwise, return 0
    return 0;
}
