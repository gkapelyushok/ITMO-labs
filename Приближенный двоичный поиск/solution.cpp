#include <iostream>
#include <vector>
using namespace std;
 
int bin_search_min(vector<long> &a, int n, long x) {
    int left = 0, right = n - 1;
    while (right - left > 1) {
        int middle = (left + right) / 2;
        if (a[middle] <= x) {
            left = middle;
        } else {
            right = middle;
        }
    }
    return right;
}
 
int bin_search_max(vector<long> &a, int n, long x) {
    int left = 0, right = n - 1;
    while (right - left > 1) {
        int middle = (left + right) / 2;
        if (a[middle] <= x) {
            left = middle;
        } else {
            right = middle;
        }
    }
    return left;
}
int main() {
    int n;
    cin >> n;
    vector<long> a(n);
    int k;
    cin >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<long> search(k);
    for (int i = 0; i < k; i++) {
        long x;
        cin >> x;
        long x1 = a[bin_search_max(a, n, x)];
        long x2 = a[bin_search_min(a, n, x)];
        if (x - x1 <= x2 - x) {
            search[i] = x1;
        } else {
            search[i] = x2;
        }
    }
    for (int i = 0; i < k; i++) {
        cout << search[i] << endl;
    }
    return 0;
}
