#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int n;
int dp[300000][18];
int mins[300000][18];
int d[300000];
int logn;

void preprocess() {
    for (int i = 0; i < logn; i++) {
        dp[0][i] = 0;
        mins[0][i] = 0;
    }
    for (int v = 1; v < n; v++) {
        cin >> dp[v][0];
        cin >> mins[v][0];
        dp[v][0]--;
    }
    for (int i = 1; i < logn; i++) {
        for (int v = 0; v < n; v++) {
            dp[v][i] = dp[dp[v][i - 1]][i - 1];
            mins[v][i] = min(mins[dp[v][i - 1]][i - 1], mins[v][i - 1]);
        }
    }
}

int get_d(int v) {
    if (d[v] == -1) {
        if (v == 0) {
            d[v] = 0;
        } else {
            d[v] = get_d(dp[v][0]) + 1;
        }
    }
    return d[v];
}

int get_min (int u, int v) {
    if (get_d(v) > get_d(u)) {
        int tmp = u;
        u = v;
        v = tmp;
    }
    int dh = get_d(u) - get_d(v);
    int res = INT32_MAX;
    for (int i = logn - 1; i >= 0; i--) {
        if (pow(2, i) <= dh) {
            res = min(res, mins[u][i]);
            u = dp[u][i];
            dh -= pow(2, i);
        }
    }
    if (v == u) {
        return res;
    }
    for (int i = logn - 1; i >= 0; i--) {
        if (dp[v][i] != dp[u][i]) {
            res = min(res, mins[v][i]);
            v = dp[v][i];
            res = min(res, mins[u][i]);
            u = dp[u][i];
        }
    }
    return min(res, min(mins[v][0], mins[u][0]));
}

int main() {
    cin >> n;
    logn = ceil(log2(n));
    for (int i = 0; i < n; i++) {
        d[i] = -1;
    }
    preprocess();
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        cout << get_min(u - 1, v - 1) << endl;
    }
    return 0;
}
