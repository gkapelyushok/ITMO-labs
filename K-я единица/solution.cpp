#include <iostream>
#include <vector>

using namespace std;

vector<int> t;

void set(int i, int value, int v, int l, int r) {
    if (r == l + 1) {
        t[v] = value;
        return;
    }
    if (i < (l + r) / 2) {
        set(i, value, 2*v+1, l, (l+r)/2);
    } else {
        set(i, value, 2*v+2,(l+r)/2, r);
    }
    t[v] = t[2*v+1] + t[2*v+2];
}

int find(int k, int i, int l, int r) {
    if (l == r - 1) {
        return l;
    }
    if (t[2*i+1] > k) {
        find(k, 2*i+1, l, (l+r)/2);
    } else {
        find(k - t[2*i+1], 2*i+2, (l+r)/2, r);
    }
}



int main() {
    int m;
    int n;
    cin >> n >> m;
    int x = 1;
    while (x < n) {
        x *= 2;
    }
    t.resize(2*x - 1);
    for (int i = 0; i < n; i++) {
        cin >> t[x - 1 + i] ;
    }
    for (int i = x - 2; i >= 0; i--) {
        t[i] = t[2 * i + 1] + t[2 * i + 2];
    }
    for (int i = 0; i < m; i++) {
        int mode;
        cin >> mode;
        if (mode == 1) {
            int id;
            cin >> id;
            if (t[x - 1 + id] == 0) {
                set(id, 1, 0, 0, x);
            } else {
                set(id, 0, 0, 0, x);
            }
        } else {
            int k;
            cin >> k;
            cout << find(k, 0, 0, x) << endl;
        }
    }


    return 0;
}
