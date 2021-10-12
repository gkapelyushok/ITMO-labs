#include <iostream>
#include <vector>

using namespace std;

int main() {
    long n;
    cin >> n;
    vector<long> a(n);
    vector<long> dp(n);
    vector<long> p(n);
    cin >> a[0];
    dp[0] = 1;
    p[0] = 0;
    for (long i = 1; i < n; i++) {
        cin >> a[i];
        dp[i] = 1;
        for (long j = 0; j < i; j++) {
            if (a[j] < a[i] && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
                p[i] = j;
            }
        }
    }
    long max = 0;
    long j = -1;
    for (long i = 0; i < n; i++) {
        if (max < dp[i]) {
            max = dp[i];
            j = i;
        }
    }
    cout << max << endl;
    vector<long> result;
    while (dp[j] != 1) {
        result.push_back(a[j]);
        j = p[j];
    }
    result.push_back(a[j]);

    for (long i = result.size() - 1; i >= 0; i--) {
        cout << result[i] << " ";
    }
}
