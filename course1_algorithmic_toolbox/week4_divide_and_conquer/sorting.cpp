// File: sorting.cpp
// Author: Phi Luu
// Created: February 05, 2018
//
// Algorithmic Toolbox - Week 4 - Divide-and-Conquer Algorithms
// See ./week4_divide_and_conquer.pdf for details

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

char c;

void Partition(std::vector<int>& array, int low, int high, int& i, int& j);
void QuickSort(std::vector<int>& array, int low, int high);
void QuickSort(std::vector<int>& array);
void Swap(int* a, int* b);

int main(void) {
    // int n;

    // std::cin >> n;
    // std::vector<int> a(n);
    // for (int i = 0; i < n; i++) std::cin >> a[i];

    std::vector<int> a;
    a.push_back(2);
    a.push_back(1);
    a.push_back(1);
    a.push_back(2);
    a.push_back(2);
    a.push_back(2);
    a.push_back(4);
    a.push_back(1);
    a.push_back(2);
    a.push_back(4);
    a.push_back(9);
    a.push_back(3);
    a.push_back(4);
    a.push_back(4);

    QuickSort(a);

    for (auto& num : a) std::cout << num << " ";
    std::cout << std::endl;

    return 0;
}

// Does 3-way partition to an arrayp[low..high-1] such that
// array[low..i-1] < pivot
// array[i..j-1] = pivot
// array[j..high-1] > pivot
void Partition(std::vector<int>& array, int low, int high, int& i, int& j) {
    // handle 2-or-less-elements case
    if (high - low <= 2) {
        std::cout << "2 OR LESS " << std::endl;
        // only swap if out of order
        if (array[low] > array[high - 1]) {
            Swap(&array[low], &array[high - 1]);
            std::cout << "indices " << low << " and " << high - 1 << std::endl;
        }


        // modify outputs and return
        i = low;
        j = high - 1;
        return;
    }

    // the point of the following 2 blocks is to
    // get  low  to the first occurrence of pivot
    // get  mid  to after the last occurrence of pivot
    int pivot = array[high - 1], mid = low;


    while (mid < high) {
        std::cout << "Pivot = " << pivot << "   ";
        std::cout << "Low = " << low << "   ";
        std::cout << "Mid = " << mid << "   ";
        std::cout << "High = " << high << std::endl;;

        for (int k = 0; k < array.size(); k++) std::cout << k % 10 << " "; std::cout << std::endl; for (auto& num : array) std::cout << num << " ";
        std::cout << std::endl << std::endl;
        std::cin >> c;
        while (c != '\'') std::cin >> c;

        if (array[mid] < pivot) {
            // every element smaller than pivot must be put before  low
            Swap(&array[mid], &array[low]);
            std::cout << "indices " << mid << " and " << low << std::endl;
            mid++;
            low++;
        } else if (array[mid] == pivot) {
            // every element equal pivot stays where it is
            mid++;
        } else {
            // every element greater than pivot must be put after  mid
            Swap(&array[mid], &array[high - 1]);
            std::cout << "indices " << mid << " and " << high - 1 << std::endl;
            high--;
        }
    }


    // modify outputs and finish
    i = low;
    j = mid;

    std::cout << "i = " << i << "   j = " << j << std::endl;
}

// Quicksorts the array from index  low  to index  high .
void QuickSort(std::vector<int>& array, int low, int high) {
    std::cout << "minlow = " << low << "   maxhigh = " << high << std::endl;
    // safely return if array has 1 element or less
    if (low >= high - 1) return;

    // chose a random pivot
    srand((unsigned int)time(nullptr));
    int pivotindex = rand() % (high - low) + low;

    std::cout << "Pivot index = " << pivotindex << std::endl;

    for (int k = 0; k < array.size(); k++) std::cout << k % 10 << " "; std::cout << std::endl; for (auto& num : array) std::cout << num << " ";
    std::cout << std::endl;
    std::cin >> c;
    while (c != '\'') std::cin >> c;

    std::cout << " NEW PARTITION" << std::endl;

    Swap(&array[high - 1], &array[pivotindex]);
    std::cout << "indices " << high - 1 << " and " << pivotindex << std::endl;

    // partition the array by 3 ways and set values for onethid and twothird
    int onethird, twothird;
    Partition(array, low, high, onethird, twothird);

    QuickSort(array, low, onethird);
    QuickSort(array, twothird, high);
}

// QuickSort driver. The user only needs to pass in the vector.
void QuickSort(std::vector<int>& array) { QuickSort(array, 0, array.size()); }

void Swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;

    std::cout << "Swapped ";
}
