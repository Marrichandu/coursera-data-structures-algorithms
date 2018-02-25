// File: points_and_segments.cpp
// Author: Phi Luu
// Created: February 05, 2018
//
// Algorithmic Toolbox - Week 4 - Divide-and-Conquer Algorithms
// See ./week4_divide_and_conquer.pdf for details

#include <algorithm>
#include <cstring>
#include <iostream>
#include <random>
#include <vector>

using std::vector;

typedef struct seg {
    int left;
    int right;
} seg;

// Sorts the left end points in a non-descending order.
struct sortleft {
    bool operator()(const seg& x, const seg& y) const {
        return x.left <= y.left;
    }
};
// Sorts the right end points in the non-descending order.
struct sortright {
    bool operator()(const seg& x, const seg& y) const {
        return x.right <= y.right;
    }
};

vector<int> CountSegments(vector<seg>& segments, vector<int>& points);
int CountSegments(vector<seg> segments, int point);
vector<int> CountSegmentsNaive(vector<seg>& segments, vector<int>& points);
void StressTest(void);

int main(int argc, char** argv) {
    if ((argc > 2) || ((argc == 2) && strcmp(argv[1], "stresstest"))) {
        std::cerr << "Usage: ./week4_points_and_segments [stresstest]"
                  << std::endl;
        return 1;
    } else if (argc == 2) {
        StressTest();
    } else {
        int n, m;

        std::cin >> n >> m;

        vector<seg> segments(n);
        for (int i = 0; i < n; i++) {
            std::cin >> segments[i].left >> segments[i].right;
        }

        vector<int> points(m);
        for (int i = 0; i < m; i++) std::cin >> points[i];

        // for each point, count the number of segments that contain it
        vector<int> count = CountSegments(segments, points);

        // print result
        for (int i = 0; i < count.size(); i++) std::cout << count[i] << ' ';
        std::cout << std::endl;
    }

    return 0;
}

vector<int> CountSegments(vector<seg>& segments, vector<int>& points) {
    vector<int> count(points.size());

    // sort left points in non-descending order
    std::sort(segments.begin(), segments.end(), sortleft());

    for (int i = 0; i < points.size(); i++) {
        count[i] = CountSegments(segments, points[i]);
    }

    return count;
}

int CountSegments(vector<seg> segments, int point) {
    // if the point is less than the lowest left then there is zero segment
    if (point < segments.front().left) return 0;

    int right = segments.size();

    // find the index of the first segment that has greater left than point
    if (point < segments.back().left) {
        int low = 0, high = segments.size();
        while (low < high) {
            int mid = (low + high) / 2;

            if (point >= segments[mid].left) {
                low = mid + 1;
            } else {
                right = mid;
                high = mid;
            }
        }
    }

    // sort the right endpoints of the portion of segment from begin to
    // before right in non-descending order
    std::sort(segments.begin(), segments.begin() + right, sortright());

    int left = 0;

    // find the index of the first segment that has smaller right-end than point
    if (point > segments.front().right) {
        int low = 0, high = right;
        while (low < high) {
            int mid = (low + high) / 2;

            if (point <= segments[mid].right) {
                high = mid;
            } else {
                left = mid + 1;
                low = mid + 1;
            }
        }
    }

    return right - left;
}

vector<int> CountSegmentsNaive(vector<seg>& segments, vector<int>& points) {
    vector<int> count(points.size());

    for (int i = 0; i < points.size(); i++) {
        for (int j = 0; j < segments.size(); j++) {
            count[i] += segments[j].left <= points[i]
                        && points[i] <= segments[j].right;
        }
    }

    return count;
}

void StressTest(void) {
    std::random_device rd;
    std::uniform_int_distribution<int> sprange(1, 50000), abxrange(-100000000,
                                                                   100000000);
    bool failed = false;
    while (!failed) {
        int s = sprange(rd), p = sprange(rd);
        std::vector<seg> segments(s);
        for (int i = 0; i < s; i++) {
            segments[i].left = abxrange(rd);
            segments[i].right = abxrange(rd);
        }
        std::vector<int> points(p);
        for (int i = 0; i < p; i++) {
            points[i] = abxrange(rd);
        }

        std::cout << "s = " << s << "  p = " << p << std::endl;
        if (s < 7) {
            for (int i = 0; i < s; i++) {
                std::cout << segments[i].left << " " << segments[i].right
                          << std::endl;
            }
        } else {
            for (int i = 0; i < 7; i++) {
                std::cout << segments[i].left << " " << segments[i].right
                          << std::endl;
            }
            std::cout << "..." << std::endl;
        }

        std::vector<int> naive = CountSegmentsNaive(segments, points);
        std::vector<int> self = CountSegments(segments, points);

        for (int i = 0; i < p; i++) {
            if (naive[i] != self[i]) {
                std::cout << "    FAILED at point i = " << i << std::endl;
                std::cout << "        naive[i] = " << naive[i] << std::endl;
                std::cout << "        self[i]  = " << self[i] << std::endl;
                failed = true;
                break;
            }
        }

        if (!failed) std::cout << "    PASSED" << std::endl << std::endl;
    }
}
