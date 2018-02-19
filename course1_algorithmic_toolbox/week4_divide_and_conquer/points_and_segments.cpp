// File: points_and_segments.cpp
// Author: Phi Luu
// Created: February 05, 2018
//
// Algorithmic Toolbox - Week 4 - Divide-and-Conquer Algorithms
// See ./week4_divide_and_conquer.pdf for details

#include <algorithm>
#include <iostream>
#include <vector>
#include <random>

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

int SegmentsContainPoint(int point, std::vector<seg>& segment);

int Naive(int point, std::vector<seg>& segment) {
    int total = 0;

    for (auto& segm : segment) {
        if ((point >= segm.a) && (point <= segm.b)) total++;
    }

    return total;
}

int main(void) {
    // std::random_device rd;
    // std::uniform_int_distribution<int> sprange(1, 50000), abxrange(-100000000,
    //                                                                100000000);
    // bool failed = false;
    // while (!failed) {
    //     int s = sprange(rd), p = sprange(rd);
    //     std::vector<seg> segment(s);
    //     for (int i = 0; i < s; i++) {
    //         segment[i].a = abxrange(rd);
    //         segment[i].b = abxrange(rd);
    //     }
    //     int x[p];
    //     for (int i = 0; i < p; i++) {
    //         x[i] = abxrange(rd);
    //     }

    //     std::cout << "s = " << s << "  p = " << p << std::endl;
    //     if (s < 7) {
    //         for (int i = 0; i < s; i++) {
    //             std::cout << segment[i].a << " " << segment[i].b << std::endl;
    //         }
    //     } else {
    //         for (int i = 0; i < 7; i++) {
    //             std::cout << segment[i].a << " " << segment[i].b << std::endl;
    //         }
    //         std::cout << "..." << std::endl;
    //     }

    //     for (int i = 0; i < p; i++) {
    //         int naive = Naive(x[i], segment);
    //         int self = SegmentsContainPoint(x[i], segment);

    //         if (naive == self) {
    //             std::cout << "    PASSED" << std::endl;
    //             std::cout << "        naive = " << naive << std::endl;
    //             std::cout << "        self  = " << self << std::endl;
    //         } else {
    //             std::cout << "    FAILED" << std::endl;
    //             std::cout << "        naive = " << naive << std::endl;
    //             std::cout << "        self  = " << self << std::endl;
    //             failed = true;
    //             break;
    //         }
    //     }
    // }
    // return 0;
    int s, p;

    std::cin >> s >> p;

    std::vector<seg> segment(s);
    for (int i = 0; i < s; i++) std::cin >> segment[i].a >> segment[i].b;

    int x[p];
    for (int i = 0; i < p; i++) std::cin >> x[i];

    for (int i = 0; i < p; i++) {
        std::cout << SegmentsContainPoint(x[i], segment) << ' ';
    }
    std::cout << std::endl;

    return 0;
}

int SegmentsContainPoint(int point, std::vector<seg>& segment) {
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
                if (found) {
                    for (int i = mid; i <= right; i++) {
                        if ((i < right) && (point < segment[i].a)) {
                            right = i;
                            break;
                        }
                    }
                    break;
                }
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
                if (found) {
                    for (int i = left; i <= mid; i++) {
                        if ((i < mid) && (point > segment[i].b)) left = i + 1;
                    }
                    break;
                }
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
