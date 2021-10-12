#include <iostream>
#include <vector>

using namespace std;

struct values {
    long long sum, pref, suf, ans;
};

vector<values> t;


values build(long long value) {
    values res{};
    res.sum = value;
    res.pref = res.suf = res.ans = max(0, (int)value);
    return res;
}

values merge(values a, values b) {
    values res{};
    res.sum = a.sum + b.sum;
    res.pref = max(a.pref, a.sum + b.pref);
    res.suf = max(b.suf, b.sum + a.suf);
    res.ans = max(max(a.ans, b.ans), a.suf + b.pref);
    return res;
}

void set(long long id, long long value, long long i, long long l, long long r) {
    if (l == r - 1) {
        t[i] = build(value);
    } else {
        if (id < (l+r)/2)
            set(id, value, 2*i+1, l, (l+r)/2);
        else
            set(id, value, 2*i+2, (l+r)/2, r);
        t[i] = merge(t[2*i+1], t[2*i+2]);
    }
}


int main() {
    long long n, m;
    cin >> n >> m;
    long long x = 1;
    while (x < n) {
        x *= 2;
    }
    vector<long long> a(x);
    for (long long i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (long long i = n; i < x; i++) {
        a[i] = long INT32_MIN;
    }
    t.resize(2*x-1);
    for (long long i = 0; i < x; i++) {
        t[x - 1 + i] = build(a[i]);
    }
    for (long long i = x - 2; i >= 0; i--) {
        t[i] = merge(t[2*i+1], t[2*i+2]);
    }
    cout << t[0].ans << endl;
    for (long long i = 0; i < m; i++) {
        long long id, value;
        cin >> id >> value;
        set(id, value, 0, 0, x);
        cout << t[0].ans << endl;
    }

    return 0;
}
