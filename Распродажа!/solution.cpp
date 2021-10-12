#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void solution() {
    int n, e, w;
    cin >> n >> e >> w;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    vector<long long> prefix(n+1);
    prefix[0] = 0;
    for (int i = 1; i <= n; i++) {
        prefix[i] = prefix[i - 1] + a[i - 1];
    }
    for (int q = 1; q <= n; q++) {
        long long result = INT64_MAX;
        long long sum = 0;
        for (int i = n; i >= 1; i -= (w + q)) {
            if (i - (w + q) >= 0) {
                result = min(result, sum + prefix[i] - prefix[w] + e);
                sum += prefix[i] - prefix[i - q] + e;
            } else {
                result = min(result, sum + prefix[i] + e);
            }
        }
        cout << result << " ";
    }
}

int main() {
    freopen("booksale.in", "r", stdin);
    freopen("booksale.out", "w", stdout);
    solution();
    return 0;
}
