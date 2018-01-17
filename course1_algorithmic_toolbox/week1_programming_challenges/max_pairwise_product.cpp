// File: max_pairwise_product.cpp
// Author: Phi Luu
// Created: January 17, 2018
//
// Algorithmic Toolbox - Week 1 - Maximum Pairwise Product
// See ./week1_programming_challenges.pdf for details

#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>

long long MaxPairwiseProduct(std::vector<int> v);
long long MaxPairwiseProductTester(std::vector<int> v);
void StressTest(void);

int main(int argc, char** argv) {
    // ensure proper usage
    if (((argc != 1) && (argc != 2))
        || ((argc == 2) && (strcmp(argv[1], "t") != 0))) {
        std::cerr << "Usage: ./week1_max_pairwise_product [t]\n";
        std::cerr << "Run with single argument  t  to stress test" << std::endl;
        return 1;
    }

    // run with an additional argument  t  to stress test
    if ((argc == 2) && (argv[1] != "t")) {
        StressTest();
    } else {
        // read from stdin
        int n;
        std::cin >> n;
        std::vector<int> a(n);
        for (int i = 0; i < n; i++) std::cin >> a[i];

        std::cout << MaxPairwiseProduct(a) << std::endl;
    }

    return 0;
}

// Returns the maximum pairwise product using a smarter way: multiplying the two
// largest elements in the sequence.
long long MaxPairwiseProduct(std::vector<int> v) {
    // imax1 = index of largest; imax2 = index of second largest
    // max1 = value of largest; max2 = value of second largest
    int imax1 = 0, imax2 = 0, max1 = 0, max2 = 0;
    int size = v.size();

    // find value and index of the largest
    for (int i = 0; i < size; i++) {
        if (v[i] > max1) {
            max1 = v[i];
            imax1 = i;
        }
    }
    // find value and index of the second largest
    for (int i = 0; i < size; i++) {
        if ((v[i] > max2) && (i != imax1)) {
            max2 = v[i];
            imax2 = i;
        }
    }

    // max pairwise is the product of the two
    return (long long)max1 * (long long)max2;
}

void StressTest(void) {
    while (true) {
        int n = rand() % 199999 + 2, count = 0;
        std::cout << n << std::endl;
        std::vector<int> a(n);

        for (int i = 0; i < n; i++) {
            a[i] = rand() % 199999;
            if (count < 7) {
                std::cout << a[i] << " ";
                count++;
            }
        }
        if (n > count) std::cout << "...";

        std::cout << std::endl;

        long long result = MaxPairwiseProduct(a),
                  result_tester = MaxPairwiseProductTester(a);

        if (result != result_tester) {
            std::cout << "WRONG ANSWER:" << std::endl;
            std::cout << "  result = " << result << std::endl;
            std::cout << "  result_tester = " << result_tester << std::endl;
            break;
        } else {
            std::cout << "PASSED: " << result << std::endl;
        }

        std::cout << std::endl;
    }
}

// Performs the test using the naive method: comparing each pair of product
// with each other and then returning the largest pairwise product.
long long MaxPairwiseProductTester(std::vector<int> v) {
    long long max = 0;
    int size = v.size();

    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            long long product = (long long)v[i] * (long long)v[j];
            if (product > max) max = product;
        }
    }

    return max;
}
