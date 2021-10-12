#include <iostream>
#include <vector>
using namespace std;
 
void swap (vector<long> &a, int i, int j) {
    long tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
}
 
void insert(vector<long> &a, int n, long x) {
    a[n] = x;
    int i = n;
    while (i > 0 && a[i] > a[(i - 1) / 2]) {
        swap(a, i, (i - 1) / 2);
        i = (i - 1) / 2;
    }
}
 
void get_max(vector<long> &a, int n, vector<long> &max, int j) {
    max[j] = a[0];
    a[0] = a[n - 1];
    int i = 0;
    while (2 * i + 1 < n) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int j = left;
        if (right < n && a[right] > a[left]) {
            j = right;
        }
        if (a[i] >= a[j]) {
            break;
        }
        swap(a, i, j);
        i = j;
    }
}
 
 
int main() {
    int n;
    cin >> n;
    vector<long> a(n);
    vector<long> max(n);
    int j = 0;
    int size = 0;
    for (int i = 0; i < n; i++) {
        int command;
        cin >> command;
        if (command == 0) {
            long x;
            cin >> x;
            insert(a, size, x);
            size++;
        } else {
            get_max(a, size, max, j);
            j++;
            size--;
        }
    }
    int k = 0;
    while (max[k] != 0) {
        cout << max[k] << endl;
        k++;
    }
    return 0;
}
