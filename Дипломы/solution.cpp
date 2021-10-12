#include <iostream>
using namespace std;

bool good(long long middle, long long h, long long w, long long n) {
    return ((middle / w) * (middle / h) >= n );
}

int main() {
    long long w, h, n;
    cin >> w >> h >> n;
    if (w > h) {
        long long tmp = w;
        w = h;
        h = tmp;
    }
    long long left = 0;
    long long right = h * n;
    while (right - left > 1) {
        long long middle = (left + right) / 2;
        if (good(middle, h, w, n)) {
            right = middle;
        } else {
            left = middle;
        }
    }
    cout << right;
    return 0;
}
