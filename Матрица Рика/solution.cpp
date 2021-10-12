#include <iostream>
#include <vector>

using namespace std;

int f(int a1, int a2, int a3, int a4) {
    if (a1 == a2 && a2 == a3 && a3 == a4) {
        return 0;
    } else if ((a1 == a2 && a2 == a3) ||
               (a1 == a2 && a2 == a4) ||
               (a1 == a3 && a3 == a4) ||
               (a2 == a3 && a3 == a4)) {
        return 1;
    } else if (a1 == a2 ||
               a1 == a3 ||
               a1 == a4 ||
               a2 == a3 ||
               a2 == a4 ||
               a3 == a4) {
        return 2;
    }
    return 3;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    int result = 0;
    if (n == 1 && m > 1) {
        for (int i = 0; i < m/2; i++) {
            if (a[0][i] != a[0][m - i - 1]) {
                result++;
            }
        }
    } else if (n > 1 && m == 1) {
        for (int i = 0; i < n/2; i++) {
            if (a[i][0] != a[n - i - 1][0]) {
                result++;
            }
        }
    } else if (n > 1 && m > 1) {
        for (int i = 0; i < n / 2; i++) {
            for (int j = 0; j < m / 2; j++) {
                result += f(a[i][j],
                            a[n - i - 1][j],
                            a[i][m - j - 1],
                            a[n - i - 1][m - j - 1]);
            }
        }
        if (n % 2 == 1) {
            for (int i = 0; i < m/2; i++) {
                if (a[n/2][i] != a[n/2][m - i - 1]) {
                    result++;
                }
            }
        }
        if (m % 2 == 1) {
            for (int i = 0; i < n/2; i++) {
                if (a[i][m/2] != a[n - i - 1][m/2]) {
                    result++;
                }
            }
        }
    }
    cout << result;
    return 0;
}
