#include <iostream>
using namespace std;
 
int main() {
    long n;
    cin >> n;
    n--;
    long x, y;
    cin >> x;
    cin >> y;
    if (x < y) {
        long tmp = x;
        x = y;
        y = tmp;
    }
    long left = 0;
    long right = n * x;
    while (right - left > 1) {
        long middle = (left + right) / 2 ;
        if (middle / x + middle / y >= n) {
            right = middle;
        } else {
            left = middle;
        }
    }
    cout << right + y;
}
