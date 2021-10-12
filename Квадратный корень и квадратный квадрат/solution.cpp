#include <iostream>
#include <cmath>
using namespace std;

double f(double x) {
    return x * x + sqrt(x);
}
int main() {
    double c;
    cin >> c;
    double count = 1;
    while (f(count) < c) {
        count *= 2;
    }
    double left = count / 2;
    double right = count;
    double EPS = 0.0000001;
    double middle;
    while (true) {
        middle = (left + right) / 2;
        if (f(middle) >= c - EPS && f(middle) <= c + EPS) {
            break;
        } else if (f(middle) < c) {
            left = middle;
        } else {
            right = middle;
        }
    }
    cout.precision(8);
    cout << (double)middle;
    return 0;
}
