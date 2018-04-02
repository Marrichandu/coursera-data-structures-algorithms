// primitive_calculator.cpp
// 
// Phi Luu
//
// Algorithmic Toolbox - Week 05 - Dynamic Programming 1
// See ./week5_dynamic_programming1.pdf for details

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

int main(void) {
    int n;
    
    cin >> n;

    int minops[n], trace[n];

    // init
    trace[1] = 1;
    minops[1] = 0;

    // work from left to right
    for (int i = 2; i <= n; i++) {
        minops[i] = minops[i - 1] + 1;
        trace[i] = i - 1;
        
        if (i % 2 == 0) {
            if (minops[i / 2] + 1 < minops[i]) {
                minops[i] = minops[i / 2] + 1;
                trace[i] = i / 2;
            } 
        }

        if (i % 3 == 0) {
            if (minops[i / 3] + 1 < minops[i]) {
                minops[i] = minops[i / 3] + 1;
                trace[i] = i / 3;
            } 
        }
    }

    // output the minimum number of said operations
    cout << minops[n] << endl;

    // print the tracing
    int j = n;
    std::string intermediate = std::to_string(n);

    while (j != 1) {
        intermediate = std::to_string(trace[j]) + ' ' + intermediate; 
        j = trace[j];
    }

    cout << intermediate << endl;

    return 0;
}
