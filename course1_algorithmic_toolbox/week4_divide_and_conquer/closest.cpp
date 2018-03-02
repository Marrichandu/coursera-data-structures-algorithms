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

typedef struct pt {
    int x;
    int y;

    bool operator<(const pt& rhs) { return x <= rhs.x; }

    pt& operator=(const pt& rhs) {
        x = rhs.x;
        y = rhs.y;

        return *this;
    }
} pt;
struct sorty {
    bool operator()(const pt& lhs, const pt& rhs) {
        return lhs.y <= rhs.y;
    }
};

double MinDistance(pt* points, int low, int high);
double MinDistance(pt* points, int size);
double Min(const pt& p1, const pt& p2, const pt& p3);
double Distance(const pt& p1, const pt& p2);

int main(void) {
    int n;

    std::cin >> n;

    pt points[n];
    for (int i = 0; i < n; i++) std::cin >> points[i].x >> points[i].y;

    // sort the points by x-coordinates in non-descending order
    std::sort(points, points + n);

    std::cout << std::fixed;
    std::cout << std::setprecision(4) << MinDistance(points, n) << std::endl;

    return 0;
}

double MinDistance(pt* points, int low, int high) {
    // if there are three points, find the minimum distance manually
    if (high - low == 3) {
        return Min(points[low], points[low + 1], points[low + 2]);
    }

    // if there are two points, the minimum distance is their distance
    if (high - low == 2) return Distance(points[low], points[low + 1]);

    // split the array in two halves
    int mid = (low + high) / 2;

    // find the minimum distance inside the left half
    double minleft = MinDistance(points, low, mid);

    // find the minimum distance inside the right half
    double minright = MinDistance(points, mid, high);

    double minhalves = std::min(minleft, minright);
    double midx = (double)(points[mid - 1].x + points[mid].x) / 2.0;

    // mark the points that are within (minhalves / 2) from midx
    int midlow = low, midhigh = high;

    // find the furthest point to the left of midx
    if (points[midlow].x < midx - minhalves) {
        int ihigh = mid;
        while (midlow < ihigh) {
            int imid = (midlow + ihigh) / 2;

            if (points[imid].x >= midx - minhalves) {
                ihigh = imid;
            } else {
                midlow = imid + 1;
            }
        }
    }

    // find the furthest point to the right of midx
    if (points[midhigh - 1].x > midx + minhalves) {
        int ilow = mid;
        while (ilow < midhigh) {
            int imid = (ilow + midhigh) / 2;

            if (points[imid].x <= midx + minhalves) {
                ilow = imid + 1;
            } else {
                midhigh = imid;
            }
        }
    }

    // if there are no points in the middle strip, return the min of two halves
    if (midlow >= midhigh) return minhalves;

    pt midstrip[midhigh - midlow];
    int midsize = 0;

    for (int i = midlow; i < midhigh; i++) midstrip[midsize++] = points[i];

    // sort the middle strip by y-coordinates in non-descending order
    std::sort(midstrip, midstrip + mid - midlow, sorty());
    std::sort(midstrip + mid - midlow, midstrip + midsize, sorty());

    // find the min distance in the middle strip
    double themin = minhalves;
    for (int i = 0; i < mid - midlow; i++) {
        for (int j = mid - midlow; j < midsize; j++) {
            double dij = Distance(midstrip[i], midstrip[j]);
            if (dij < themin) themin = dij;
        }
    }

    return themin;
}

double MinDistance(pt* points, int size) {
    return MinDistance(points, 0, size);
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
