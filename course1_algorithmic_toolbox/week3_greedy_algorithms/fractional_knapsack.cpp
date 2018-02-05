// File: fractional_knapsack.cpp
// Author: Phi Luu
// Created: February 04, 2018
//
// Algorithmic Toolbox - Week 03 - Greedy Algorithms
// See ./week3_greedy_algorithms.pdf for details

#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <vector>

int main(void) {
    int n, capacity;

    std::cin >> n >> capacity;

    typedef struct loot {
        int value;
        int weight;
        double ratio;

        // greater value per weight ratio, greater the "value" of the loot
        bool operator<(const loot& rhs) const { return ratio < rhs.ratio; }
    } loot;

    std::vector<loot> item(n);

    for (int i = 0; i < n; i++) {
        std::cin >> item[i].value >> item[i].weight;
        item[i].ratio = item[i].value / (double)item[i].weight;
    }

    // sort items by value per weight ratio from max to min
    std::sort(item.rbegin(), item.rend());

    double maxval = 0;
    int w = capacity;

    for (int i = 0; (i < n) && (w > 0); i++) {
        // if the capacity is still enough for the greatest item
        if (w >= item[i].weight) {
            // take the entire unit of that item
            maxval += (double)item[i].value;
            // update the remaining capacity
            w -= item[i].weight;
        }
        // otherwise if the capacity is not enough
        else {
            // fill the bag with the greatest fraction of the item
            maxval += w / (double)item[i].weight * item[i].value;
            // the bag is now full
            w = 0;
        }
    }

    // output the answer with 4 decimal places
    printf("%.4f\n", maxval);

    return 0;
}
