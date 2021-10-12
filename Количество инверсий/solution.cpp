#include <iostream>
#include <vector>
using namespace std;
long long inv = 0;
 
void merge(vector<long> &a, long left, long middle, long right) {
    vector<long> b(right - left);
    long i = left;
    long j = middle;
    long k = 0;
 
    while (k < right - left) {
        if (i == middle) {
            b[k] = a[j];
            j++;
            //inv += middle - i;
        } else if (j == right) {
            b[k] = a[i];
            i++;
        } else if (a[i] <= a[j]) {
            b[k] = a[i];
            i++;
        } else {
            b[k] = a[j];
            j++;
            inv += middle - i;
        }
        k++;
    }
    copy(b.begin(), b.end(), a.begin() + left);
}
 
void merge_sort(vector<long> &a, long left, long right) {
    if (left == right - 1)
        return;
    long middle = (left + right) / 2;
    merge_sort(a, left, middle);
    merge_sort(a, middle, right);
    merge(a, left, middle, right);
 
}
 
int main() {
    long n;
    cin >> n;
    vector<long> a(n);
    for (long i = 0; i < n; i++) {
        cin >> a[i];
    }
    merge_sort(a, 0, n);
    cout << inv;
 
    return 0;
}
