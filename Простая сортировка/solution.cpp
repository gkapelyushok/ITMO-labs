#include <iostream>
#include <vector>
using namespace std;
 
void merge(vector<int> &a, int left, int middle, int right) {
    vector<int> b(right - left);
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
 
void merge_sort(vector<int> &a, int left, int right) {
    if (left == right - 1)
        return;
    int middle = (left + right) / 2;
    merge_sort(a, left, middle);
    merge_sort(a, middle, right);
    merge(a, left, middle, right);
}
 
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    merge_sort(a, 0, n);
 
    for (int j = 0; j < n; j++) {
        cout << a[j] << " ";
    }
    return 0;
}
