// File: inversions.cpp
// Author: Phi Luu
// Created: February 05, 2018
//
// Algorithmic Toolbox - Week 4 - Divide-and-Conquer Algorithms
// See ./week4_divide_and_conquer.pdf for details

#include <iostream>

long long MergeSort(int* array, int size, int low, int high);
long long Merge(int* array, int size, int low, int mid, int high);
long long MergeSort(int* array, int size);

int main(void) {
    int n;

    std::cin >> n;

    int a[n];
    for (int i = 0; i < n; i++) std::cin >> a[i];

    std::cout << MergeSort(a, n) << std::endl;

    return 0;
}

// Divides an array into two halves, sorts each half, then merge the two sorted
// halves back together. Returns the number of inversions in the original array.
long long MergeSort(int* array, int size, int low, int high) {
    // count the number of inversions in the array
    // if i < j and a[i] > a[j] then i and j are counted as one inversion
    long long inversions = 0;

    // only split and merge if array has two or more elements
    if (high - low >= 2) {
        int mid = (low + high) / 2;
        inversions = MergeSort(array, size, low, mid);
        inversions += MergeSort(array, size, mid, high);
        inversions += Merge(array, size, low, mid, high);
    }

    return inversions;
}

// Merges two sorted arrays into one single sorted array. Returns the number of
// inversion pairs in the two original arrays.
long long Merge(int* array, int size, int low, int mid, int high) {
    int left = low, right = mid;  // iterator for two respective arrays
    int i = low;  // for merged array
    int merged[size];  // temporarily hold merged elements from two arrays
    long long inversions = 0;

    // do until one of the subarrays is merged
    while ((left < mid) && (right < high)) {
        // if there are elments on the left and (right empty or left <= right)
        if (array[left] <= array[right]) {
            // merge the one on the left
            merged[i] = array[left];
            i++;
            left++;
        } else {
            // merge the one on the right
            merged[i] = array[right];
            i++;
            right++;

            // choosing the one on the right means left and right are inversions
            // if a[left] > a[right], then for every next element of the left
            // subarray, each of them is also greater than a[right]
            // there are (mid - left) elements left on the left subarray
            inversions += (long long)mid - (long long)left;
        }
    }

    // merge the remaining elements of the left subarray
    while (left < mid) {
        merged[i] = array[left];
        i++;
        left++;
    }

    // merge the remaining elements of the right subarray
    while (right < high) {
        merged[i] = array[right];
        i++;
        right++;
    }

    // merge back to the original array
    for (int i = low; i < high; i++) array[i] = merged[i];

    return inversions;
}

// Mergesort driver
long long MergeSort(int* array, int size) {
    return MergeSort(array, size, 0, size);
}
