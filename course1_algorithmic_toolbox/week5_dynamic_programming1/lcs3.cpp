// lcs3.cpp
//
// Phi Luu
//
// Algorithmic Toolbox - Week 05 - Dynamic Programming 1
// See ./week5_dynamic_programming1.pdf for details

#include <algorithm>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main(void) {
    int n, m, p;

    // read inputs
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    cin >> m;
    int b[m];
    for (int i = 0; i < m; i++) cin >> b[i];

    cin >> p;
    int c[p];
    for (int i = 0; i < p; i++) cin >> c[i];

    // init table
    // lcs[i][j][k] = length of longest common subsequence of
    // A[0..i], B[0..j], and C[0..k]
    int lcs[n][m][p];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            for (int k = 0; k < p; k++)
                lcs[i][j][k] = 0;

    bool matched = false;
    for (int j = 0; j < m; j++) {
        if ((a[0] == b[j] && b[j] == c[0]) || matched) {
            matched = true;
            lcs[0][j][0] = 1;
        } else {
            lcs[0][j][0] = 0;
        }
    }

    matched = false;
    for (int k = 0; k < p; k++) {
        if ((a[0] == b[0] && b[0] == c[k]) || matched) {
            matched = true;
            lcs[0][0][k] = 1;
        } 
        else {
            lcs[0][0][k] = 0; 
        }
    }

    // dp
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if ((lcs[i - 1][j - 1] != lcs[i - 1][j])
                    || (lcs[i - 1][j - 1] != lcs[i][j - 1])) {
                // lcs[i][j] = std::max(lcs[i - 1][j], lcs[i][j - 1]);
            } else {
                // lcs[i][j] = lcs[i - 1][j] + (a[i] == b[j]);
            }
        }
    }

    // output
    // cout << lcs[n - 1][m - 1] << endl;

    return 0;
}
