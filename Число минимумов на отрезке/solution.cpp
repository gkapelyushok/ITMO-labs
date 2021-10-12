#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> t;

pair<int, int> combine(pair<int, int> a, pair<int, int> b) {
    if (a.first < b.first) {
        return a;
    } else if (a.first > b.first) {
        return b;
    }
    return make_pair(a.first, a.second + b.second);
}

void set(int id, int value, int i, int l, int r) {
    if (l == r - 1) {
        t[i].first = value;
        return;
    }

    if (id < (l+r)/2) {
        set(id, value, 2*i+1, l, (l+r)/2);
    } else {
        set(id, value, 2*i+2, (l+r)/2, r);
    }
    t[i] = combine(t[2*i+1], t[2*i+2]);
}

pair<int, int> get(int a, int b, int i, int l, int r) {
    if (a >= r || b <= l) {
        return make_pair(INT32_MAX, 0);
    } else if (a <= l && b >= r) {
        return t[i];
    } else {
        return combine(get(a, b, 2*i+1, l, (l+r)/2),
                       get(a, b, 2*i+2, (l+r)/2, r));
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    int x = 1;
    while (x < n) {
        x *= 2;
    }
    vector<int> a(x);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = n; i < x; i++) {
        a[i] = INT32_MAX;
    }
    t.resize(2*x-1);
    for (int i = 0; i < x; i++) {
        t[x - 1 + i].first = a[i];
        t[x - 1 + i].second = 1;
    }
    for (int i = x - 2; i >= 0; i--) {
        t[i] = combine(t[2*i+1], t[2*i+2]);
    }
    for (int i = 0; i < m; i++) {
        int mode;
        cin >> mode;
        if (mode == 1) {
            int id, value;
            cin >> id >> value;
            set(id, value, 0, 0, x);
        } else {
            int a, b;
            cin >> a >> b;
            pair<int, int> c = get(a, b, 0, 0, x);
            cout << c.first << " " << c.second << endl;
        }
    }
}
 
