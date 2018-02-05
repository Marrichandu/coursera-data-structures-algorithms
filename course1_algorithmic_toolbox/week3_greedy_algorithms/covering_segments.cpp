// File: covering_segments.cpp
// Author: Phi Luu
// Created: February 05, 2018
//
// Algorithmic Toolbox - Week 03 - Greedy Algorithms
// See ./week3_greedy_algorithms.pdf for details

#include <algorithm>
#include <iostream>
#include <vector>

int main(void) {
    int n;

    std::cin >> n;

    typedef struct segments {
        int left;
        int right;
        bool iscovered;

        // enables sort by the right point of the segment
        bool operator<(const segments& rhs) { return right < rhs.right; }
    } segments;

    std::vector<segments> segment(n);

    for (int i = 0; i < n; i++) {
        std::cin >> segment[i].left >> segment[i].right;
        segment[i].iscovered = false;
    }

    // sort the segments by min right point to max right point
    std::sort(segment.begin(), segment.end());

    std::vector<int> pointlist;  // store the list of the points to cover
    int num_covered = 0;  // number of segements that are already covered.
    int i = 0;  // index of segment list

    while (num_covered < n) {
        // if the ith segment is not covered then chose it as the optimal point
        if (!segment[i].iscovered) {
            // select the point = the right point of the ith segment
            int point = segment[i].right;
            // update the list of optimal points
            pointlist.push_back(point);

            // since the list is sorted by min right point to max right point,
            // only check for the segments on the right
            for (int j = i; j < n; j++) {
                if (!segment[j].iscovered && (point >= segment[j].left)
                    && (point <= segment[j].right)) {
                    // mark the segment as covered
                    segment[j].iscovered = true;
                    num_covered++;
                }
            }
        }

        // go on to the segment with the next smallest right point
        i++;
    }

    // output the number of optimal points and the list of them
    std::cout << pointlist.size() << std::endl;
    for (auto& point : pointlist) std::cout << point << " ";
    std::cout << std::endl;

    return 0;
}
