// File: closest.cpp
// Author: Phi Luu
// Created: February 05, 2018
//
// Algorithmic Toolbox - Week 4 - Divide-and-Conquer Algorithms
// See ./week4_divide_and_conquer.pdf for details

#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>

typedef struct pt {
    int x;
    int y;

    bool operator<(const pt& rhs) { return x <= rhs.x; }
} pt;
struct sorty {
    bool operator()(const pt& lhs, const pt& rhs) { return lhs.y <= rhs.y; }
};

double MinDistance(const std::vector<pt>& points);
double Min(const pt& p1, const pt& p2, const pt& p3);
double Distance(const pt& p1, const pt& p2);

int main(void) {
    int n;

    std::cin >> n;

    std::vector<pt> points(n);
    for (int i = 0; i < n; i++) std::cin >> points[i].x >> points[i].y;

    // sort the points by x-coordinates in non-descending order
    std::sort(points.begin(), points.end());

    std::cout << std::fixed;
    std::cout << std::setprecision(4) << MinDistance(points) << std::endl;

    return 0;
}

double MinDistance(const std::vector<pt>& points) {
    // if there are three points, find the minimum distance manually
    if (points.size() == 3) return Min(points[0], points[1], points[2]);

    // if there are two points, the minimum distance is their distance
    if (points.size() == 2) return Distance(points[0], points[1]);

    // split the array in two halves
    int mid = points.size() / 2;

    // find the minimum distance inside the left half
    std::vector<pt> lefthalf(points.begin(), points.begin() + mid);
    double minleft = MinDistance(lefthalf);

    // find the minimum distance inside the right half
    std::vector<pt> righthalf(points.begin() + mid, points.end());
    double minright = MinDistance(righthalf);

    double minhalves = std::min(minleft, minright);
    double midx = (double)(points[mid - 1].x + points[mid].x) / 2.0;

    // mark the points that are within (minhalves / 2) from midx
    int midlow = 0, midhigh = points.size();

    // find the furthest point to the left of midx
    if (points.front().x < midx - minhalves) {
        int low = 0, high = mid;
        while (low < high) {
            int med = (low + high) / 2;

            if (points[med].x >= midx - minhalves) {
                high = med;
            } else {
                low = med + 1;
            }
        }
        midlow = low;
    }

    // find the furthest point to the right of midx
    if (points.back().x > midx + minhalves) {
        int low = mid, high = points.size();
        while (low < high) {
            int med = (low + high) / 2;

            if (points[med].x <= midx + minhalves) {
                low = med + 1;
            } else {
                high = med;
            }
        }
        midhigh = high;
    }
}

double Min(const pt& p1, const pt& p2, const pt& p3) {
    double d12 = Distance(p1, p2);
    double d13 = Distance(p1, p3);
    double d23 = Distance(p2, p3);

    return std::min(std::min(d12, d13), d23);
}

double Distance(const pt& p1, const pt& p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}
