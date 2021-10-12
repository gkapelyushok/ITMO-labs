#include <iostream>
#include <vector>


using namespace std;


int main() {
    int n, k;
    cin >> n >> k;
    vector<int> cost(n);
    vector<int> dp(n);
    vector<int> p(n);
    cost[0] = 0;
    cost[n - 1] = 0;
    for (int i = 1; i < n - 1; i++) {
        cin >> cost[i];
    }
    p[0] = -1;
    dp[0] = 0;
    for (int i = 1; i < n; i++) {
        int max = -10001;
        int j = i - k;
        if (j < 0) {
            j = 0;
        }
        for (; j < i; j++) {
            if (max < dp[j]) {
                max = dp[j];
                p[i] = j;
            }
        }
        dp[i] = max + cost[i];
    }
    cout << dp[n - 1] << endl;
    int i = n - 1;
    int cnt = -1;
    vector<int> result;
    while (i != -1) {
        cnt++;
        result.push_back(i + 1);
        i = p[i];
    }
    cout << cnt << endl;
    for (int j = result.size() - 1; j >= 0; j--) {
        cout << result[j] << " ";
    }

    return 0;
}
