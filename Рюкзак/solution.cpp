#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

vector<int> solution() {
    int n;
    long long W;
    cin >> n >> W;
    vector<pair<int, int>> w(n);
    for (int i = 0; i < n; i++) {
        cin >> w[i].first;
        w[i].second = i + 1;
    }
    sort(w.begin(), w.end(), [&](pair<int, int> l, pair<int, int> r){return l.first > r.first;});
    vector<int> result;
    long long cnt = 0;
    for (int i = 0; i < n; i++) {
        if (w[i].first + cnt <= W && w[i].first + cnt >= ceil((long double)W/2)) {
            result.push_back(w[i].second);
            return result;
        } else if (w[i].first + cnt < ceil((long double)W/2)) {
            result.push_back(w[i].second);
            cnt += w[i].first;
        }
    }
    return {-1};
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        vector<int> result = solution();
        if (result[0] != -1) {
            cout << result.size() << endl;
        }
        for (int j : result) {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}
