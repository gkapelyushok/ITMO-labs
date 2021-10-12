#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
int main() {
    int n;
    cin >> n;
    int logn = ceil(log2(n));
    vector<vector<int>> dp(n, vector<int>(logn, -1));
    for (int v = 0; v < n; v++) {
        cin >> dp[v][0];
        dp[v][0]--;
    }
    for (int i = 1; i < logn; i++) {
        for (int v = 0; v < n; v++) {
            if (dp[v][i - 1] == -1) {
                continue;
            }
            dp[v][i] = dp[dp[v][i - 1]][i - 1];
        }
    }
    for (int i = 0; i < n; i++) {
        cout << i + 1 << ": ";
        for (int j = 0; j < logn; j++) {
            if (dp[i][j] != -1)
                cout << dp[i][j] + 1 << " ";
        }
        cout << endl;
    }
    return 0;
}
