#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution () {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> l(n);
    int cnt = 0;
    vector<int> tmp;
    for (int i = 0; i < n; i++) {
        cin >> l[i];
        if (!l[i]) {
            tmp.push_back(a[i]);
            cnt++;
        }

    }
    if (!cnt) {
        return a;
    }
    sort(tmp.begin(), tmp.end());
    for (int i = 0; i < n; i++) {
        if (!l[i]) {
            a[i] = tmp.back();
            tmp.pop_back();
        }
    }
    return a;
};


int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        vector<int> result = solution();
        for (int j = 0; j < result.size(); j++) {
            cout << result[j] << " ";
        }
        cout << endl;
    }
    return 0;
}
