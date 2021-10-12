#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> cost(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> cost[i][j];
        }
    }
    vector<vector<int>> dp(n, vector<int>(m));
    dp[0][0] = cost[0][0];
    for (int i = 1; i < n; i++) {
        dp[i][0] = dp[i - 1][0] + cost[i][0];
    }
    for (int i = 1; i < m; i++) {
        dp[0][i] = dp[0][i - 1] + cost[0][i];
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + cost[i][j];
        }
    }
    string way;
    int i = n - 1;
    int j = m - 1;
    while (i > 0 && j > 0) {
        if (dp[i - 1][j] > dp[i][j - 1]) {
            way = "D" + way;
            i--;
        }
        else {
            way = "R" + way;
            j--;
        }
    }
    for (; i > 0; i--) {
        way = "D" + way;
    }
    for (; j > 0; j--) {
        way = "R" + way;
    }
    cout << dp[n-1][m-1] << endl;
    cout << way;
    return 0;
}
