// edit_distance.cpp
//
// Phi Luu
//
// Algorithmic Toolbox - Week 05 - Dynamic Programming 1
// See ./week5_dynamic_programming1.pdf for details

#include <algorithm>
#include <climits>
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::min;
using std::string;

int main(void) {
    string up = "", down = "";

    std::getline(cin, up);
    std::getline(cin, down);

    int n = up.length(), m = down.length(), sub = 0;
    int minedit[n + 1][m + 1];

    // init
    for (int i = 0; i <= n; i++) minedit[i][0] = i;
    for (int j = 0; j <= m; j++) minedit[0][j] = j;

    // work from top left to bottom right
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            minedit[i][j] = INT_MAX;

            // try insertion
            minedit[i][j] = min(minedit[i][j], minedit[i - 1][j] + 1);
            // try deletion
            minedit[i][j] = min(minedit[i][j], minedit[i][j - 1] + 1);
            // try substitution or do nothing if match
            if (up[i - 1] == down[j - 1]) {
                sub = 0;
            } else {
                sub = 1;
            }
            minedit[i][j] = min(minedit[i][j], minedit[i - 1][j - 1] + sub);
        }
    }

    // print minedit[n][m] which is the min edit distance of the two strings
    cout << minedit[n][m] << endl;

    return 0;
}
