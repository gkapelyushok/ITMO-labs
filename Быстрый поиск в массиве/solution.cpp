#include <iostream>
#include <vector>
using namespace std;
 
void merge(vector<long> &a, int left, int middle, int right) {
    vector<long> b(right - left);
    int i = left;
    int j = middle;
    int k = 0;
 
    while (k < right - left) {
        if (i == middle) {
            b[k] = a[j];
            j++;
        } else if (j == right) {
            b[k] = a[i];
            i++;
        } else if (a[i] < a[j]) {
            b[k] = a[i];
            i++;
        } else {
            b[k] = a[j];
            j++;
        }
        k++;
    }
    copy(b.begin(), b.end(), a.begin() + left);
}
 
void merge_sort(vector<long> &a, int left, int right) {
    if (left == right - 1)
        return;
    int middle = (left + right) / 2;
    merge_sort(a, left, middle);
    merge_sort(a, middle, right);
    merge(a, left, middle, right);
}
int bin_search_min(vector<long> &a, int n, long x) {
    int left = -1, right = n;
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
    int left = -1, right = n;
    while (right - left > 1) {
        int middle = (left + right) / 2;
        if (a[middle] < x) {
            left = middle;
        } else {
            right = middle;
        }
    }
    return right;
}
 
void bin_count(vector<long> &a, int n, vector<int> &count, int k, long l, long r) {
    count[k] = bin_search_min(a, n, r) - bin_search_max(a, n, l);
}
int main() {
    int n;
    cin >> n;
    vector<long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    merge_sort(a, 0, n);
    int k;
    cin >> k;
    vector<int> count(k);
    for (int i = 0; i < k; i++) {
        long l;
        cin >> l;
        long r;
        cin >> r;
        bin_count(a, n, count, i, l, r);
    }
    for (int i = 0; i < k; i++) {
        cout << count[i] << " ";
    }
    return 0;
}
