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
    std::vector<pt> leftpoints(points.begin(), points.begin() + mid);
    std::vector<pt> rightpoints(points.begin() + mid, points.end());

    // the minimum distance of the entire array is the min of the two halves
    return std::min(MinDistance(leftpoints), MinDistance(rightpoints));
}

double Min(const pt& p1, const pt& p2, const pt& p3) {
    const double EPSILON = 0.00001;
    double d12 = Distance(p1, p2);
    double d13 = Distance(p1, p3);
    double d23 = Distance(p2, p3);
    double min = d12;

    if (d13 - min < 0) min = d13;
    if (d23 - min < 0) min = d23;

    return min;
}

double Distance(const pt& p1, const pt& p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}
