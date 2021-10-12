#include <iostream>

using namespace std;

int minn[400000];
int upd[400000];
int x = 1;

int getValue(int i) {
    if (upd[i] != -1)  {
        return upd[i];
    }
    return minn[i];
}

void push(int i) {
    if (upd[i] == -1) {
        return;
    }
    if (i > x - 2) {
        minn[i] = upd[i];
        upd[i] = -1;
        return;
    }
    upd[2*i+1] = upd[i];
    upd[2*i+2] = upd[i];
    minn[i] = min(getValue(2*i+1),
                     getValue(2*i+2));
    upd[i] = -1;
}

void set(int value, int a, int b, int i, int l, int r) {
    if (l >= b || r <= a) {
        return;
    }
    if (l >= a && r <= b) {
        upd[i] = value;
    }
    if (i > x - 2) {
        return;
    }
    push(i);
    if (!(l >= a && r <= b)) {
        set(value, a, b, 2 * i + 1, l, (l + r) / 2);
        set(value, a, b, 2 * i + 2, (l + r) / 2, r);
    }
    minn[i] = min(getValue(2*i+1),
                     getValue(2*i+2));
}

int rmq(int a, int b, int i, int l, int r) {
    if (l >=b || r <= a) {
        return INT32_MAX;
    }
    if (l >= a && r <= b) {
        return getValue(i);
    }
    push(i);
    return min(rmq(a, b, 2*i+1, l, (l+r)/2),
               rmq(a, b, 2*i+2, (l+r)/2, r));
}

int main() {
    int n, m;
    cin >> n >> m;
    while(x < n) {
        x *= 2;
    }
    fill(begin(upd), end(upd), -1);
    for (int i = 0; i < n; i++) {
        minn[x - 1 + i] = 0;
    }
    for (int i = n; i < x; i++) {
        minn[x - 1 + i] = INT32_MAX;
    }
    for (int i = x-2; i >= 0; i--) {
        minn[i] = min(minn[2*i+1], minn[2*i+2]);

    }
    for (int i = 0; i < m; i++) {
        int mode;
        cin >> mode;
        int a, b;
        cin >> a >> b;
        if (mode == 1) {
            int value;
            cin >> value;
            set(value, a, b, 0, 0, x);
        } else {
            cout << rmq(a, b, 0, 0, x) << endl;
        }
    }
    return 0;
}
