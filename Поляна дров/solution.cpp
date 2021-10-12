#include <iostream>
#include <cmath>
using namespace std;

double good(double x, double p, double f, double a) {
    return (sqrt((1 - a) * (1 - a) + x * x) / p
            + sqrt((1 - x) * (1 - x) + a * a) / f);
}
int main() {
    double p, f;
    cin >> p >> f;
    double a;
    cin >> a;
    double left = 0;
    double right = 1;
    double EPS = 0.00001;
    double c, b;
    while (right - left > EPS) {
        c = (left * 2 + right) / 3;
        b = (left + right * 2) / 3;
        if (good(c, p, f, a) < good(b, p, f, a)) {
            right = b;
        } else {
            left = c;
        }
    }
    cout.precision(10);
    cout << (left + right) / 2;
    return 0;
}
