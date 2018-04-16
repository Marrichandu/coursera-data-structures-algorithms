// lcs2.cpp
//
// Phi Luu
//
// Algorithmic Toolbox - Week 05 - Dynamic Programming 1
// See ./week5_dynamic_programming1.pdf for details

#include <algorithm>
#include <iostream>

using std::endl;
using std::cin;
using std::cout;

int main(void) {
    int n, m;

    // read inputs
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    cin >> m;
    int b[m];
    for (int i = 0; i < m; i++) cin >> b[i];

    // init table
    // lcs[i][j] = length of longest common subsequence of A[0..i] and B[0..j]
    int lcs[n][m];
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) lcs[i][j] = 0;

    // init first row and first column
    bool isin = false;
    for (int j = 0; j < m; j++) {
        if ((a[0] == b[j]) || isin) {
            lcs[0][j] = 1;
            isin = true;
        } else {
            lcs[0][j] = 0;
        }
    }
    isin = false;
    for (int i = 0; i < n; i++) {
        if ((a[i] == b[0]) || isin) {
            lcs[i][0] = 1;
            isin = true;
        } else {
            lcs[i][0] = 0;
        }
    }

    // dp
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if ((lcs[i - 1][j - 1] != lcs[i - 1][j])
                || (lcs[i - 1][j - 1] != lcs[i][j - 1])) {
                lcs[i][j] = std::max(lcs[i - 1][j], lcs[i][j - 1]);
            } else {
                lcs[i][j] = lcs[i - 1][j] + (a[i] == b[j]);
            }
        }
    }

    // output
    cout << lcs[n - 1][m - 1] << endl;

    return 0;
}
