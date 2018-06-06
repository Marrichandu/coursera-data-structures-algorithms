// change_dp.cpp
//
// Phi Luu
//
// Algorithmic Toolbox - Week 05: Dynamic Programming 1
// See ./week5_dynamic_programming1.pdf for details.

#include <algorithm>
#include <climits>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main(void) {
    const int NUM_COINS = 3;
    const int COINS[NUM_COINS] = { 1, 3, 4 };
    int money, coins_ij;

    cin >> money;
    
    // mincoins[i] = minimum number of coins of value 1/3/4 needed
    // to change money of value i
    int mincoins[money + 1];

    // there is 0 coins needed to change money of value 0
    mincoins[0] = 0;

    // work from left to right
    for (int i = 1; i <= money; i++) {
        mincoins[i] = INT_MAX;
        for (int j = 0; j < NUM_COINS; j++) {
            if (i >= COINS[j]) {
                mincoins[i] = std::min(mincoins[i], mincoins[i - COINS[j]] + 1); 
            }
        }
    }
    
    cout << mincoins[money] << endl;

    return 0;
}
