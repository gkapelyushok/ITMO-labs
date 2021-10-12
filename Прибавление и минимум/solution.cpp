#include <iostream>

using namespace std;

long long minn[400000];
long long upd[400000];
long long x = 1;

long long getValue(long long i) {
    return minn[i] + upd[i];
}

void push(long long i) {
    if (i > x - 2) {
        minn[i] += upd[i];
        upd[i] = 0;
        return;
    }
    upd[2*i+1] += upd[i];
    upd[2*i+2] += upd[i];
    minn[i] = min(getValue(2*i+1),
                  getValue(2*i+2));
    upd[i] = 0;
}

void add(long long value, long long a, long long b, long long i, long long l, long long r) {
    if (l >= b || r <= a) {
        return;
    }
    if (l >= a && r <= b) {
        upd[i] += value;
    }
    push(i);
    if (i > x - 2) {
        return;
    }
    if(!(l >= a && r <= b)) {
        add(value, a, b, 2 * i + 1, l, (l + r) / 2);
        add(value, a, b, 2 * i + 2, (l + r) / 2, r);
    }
    minn[i] = min(getValue(2*i+1),
                  getValue(2*i+2));
}

long long rmq(long long a, long long b, long long i, long long l, long long r) {
    if (l >=b || r <= a) {
        return LONG_LONG_MAX;
    }
    if (l >= a && r <= b) {
        return getValue(i);
    }
    push(i);
    return min(rmq(a, b, 2*i+1, l, (l+r)/2),
               rmq(a, b, 2*i+2, (l+r)/2, r));
}

int main() {
    long long n, m;
    cin >> n >> m;
    while(x < n) {
        x *= 2;
    }
    fill(begin(upd), end(upd), 0);
    for (long long i = 0; i < n; i++) {
        minn[x - 1 + i] = 0;
    }
    for (long long i = n; i < x; i++) {
        minn[x - 1 + i] = LONG_LONG_MAX;
    }
    for (long long i = x-2; i >= 0; i--) {
        minn[i] = min(minn[2*i+1], minn[2*i+2]);
    }
    for (long long i = 0; i < m; i++) {
        long long mode;
        cin >> mode;
        long long a, b;
        cin >> a >> b;
        if (mode == 1) {
            long long value;
            cin >> value;
            add(value, a, b, 0, 0, x);
        } else {
            cout << rmq(a, b, 0, 0, x) << endl;
        }
    }
    return 0;
}
