// File: points_and_segments.cpp
// Author: Phi Luu
// Created: February 05, 2018
//
// Algorithmic Toolbox - Week 4 - Divide-and-Conquer Algorithms
// See ./week4_divide_and_conquer.pdf for details

#include <algorithm>
#include <iostream>
#include <vector>

typedef struct seg {
    int a;
    int b;
} seg;
struct leftascending {
    bool operator()(const seg& x, const seg& y) const { return x.a < y.a; }
};
struct rightascending {
    bool operator()(const seg& x, const seg& y) const { return x.b < y.b; }
};

int PrintSegmentsContain(int point, std::vector<seg>& segment);

int main(void) {
    int s, p;

    std::cin >> s >> p;

    std::vector<seg> segment(s);
    for (int i = 0; i < s; i++) std::cin >> segment[i].a >> segment[i].b;

    int x[p];
    for (int i = 0; i < p; i++) std::cin >> x[i];

    for (int i = 0; i < p; i++) {
        std::cout << PrintSegmentsContain(x[i], segment) << ' ';
    }
    std::cout << std::endl;

    return 0;
}

int PrintSegmentsContain(int point, std::vector<seg>& segment) {
    // std::sort(segment.begin(), segment.end(), leftascending());

    // while (point < segment.back().a) {
    //     segment.pop_back();
    //     if (segment.empty()) return 0;
    // }


    // std::sort(segment.rbegin(), segment.rend(), rightascending());

    // while (point > segment.back().b) {
    //     segment.pop_back();
    //     if (segment.empty()) return 0;
    // }

    // return segment.size();

    // check the left-ends
    std::sort(segment.begin(), segment.end(), leftascending());

    // if the point is less than the lowest left-end then there is zero segment
    if (point < segment[0].a) return 0;

    int right = segment.size();

    // find the index of the first segment that has greater left-end than point
    if (point <= segment.back().a) {
        int low = 0, high = segment.size();
        bool found = false;
        while (low < high) {
            int mid = (low + high) / 2;

            if (point >= segment[mid].a) {
                if (found) break;
                low = mid + 1;
            } else {
                right = mid;
                high = mid;
                found = true;
            }
        }
    }

    // check the right-ends
    std::sort(segment.begin(), segment.begin() + right, rightascending());

    // if the point is more than the highest right-end then there is zero segment
    if (point > segment[right - 1].b) return 0;

    int left = 0;

    // find the index of the first segment that has smaller right-end than point
    if (point >= segment.front().b) {
        int low = 0, high = right;
        bool found = false;
        while (low < high) {
            int mid = (low + high) / 2;

            if (point <= segment[mid].b) {
                if (found) break;
                high = mid;
            } else {
                left = mid + 1;
                low = mid + 1;
                found = true;
            }
        }
    }

    return right - left;
}
