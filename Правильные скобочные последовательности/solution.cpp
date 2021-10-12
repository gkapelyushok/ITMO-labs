#include <iostream>
#include <cmath>
using namespace std;

int d[31][31];
double fact[31];

int main() {
    d[0][0] = 1;
    for (int i = 1; i < 31; i++) {
        d[0][i] = 0;
    }
    for (int i = 1; i < 31; i++) {
        for (int j = 0; j < 31; j++) {
            if (j > 0) {
                d[i][j] = d[i - 1][j - 1] + d[i - 1][j + 1];
            } else {
                d[i][j] = d[i - 1][j + 1];
            }
        }
    }
    int n, k;
    cin >> n >> k;
    fact[0] = 1;
    for (int i = 1; i <= 30; i++) {
        fact[i] = fact[i-1]*i;
    }
    double c = fact[2*n]/(fact[n] * fact[n] * (n + 1));
    for (double p = k; p <= c; p += k) {
        int depth = 0;
        string s = "";
        double m = p;
        for (int i = 0; i < 2 * n; i++) {
            if (d[2 * n - (i + 1)][depth + 1] >= m) {
                s += '(';
                depth++;
            } else {
                m -= d[2 * n - (i + 1)][depth + 1];
                s += ')';
                depth--;
            }
        }
        cout << s << endl;
    }
    return 0;
}
