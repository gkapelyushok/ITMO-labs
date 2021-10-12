#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    vector<int> a;
    vector<int> b;
    int res = 0;
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        if (a.empty()) {
            a.push_back(x);
            b.push_back(1);
        } else {
            if (a.back() == x) {
                b[b.size() - 1]++;
            } else {
                if (b.back() >= 3) {
                    res += b.back();
                    a.pop_back();
                    b.pop_back();
                }
                if (a.empty() || a.back() != x) {
                    a.push_back(x);
                    b.push_back(1);
                } else {
                    b[b.size() - 1]++;
                }
            }
        }
    }
    if (b.back() >= 3) {
        res += b.back();
    }
    printf("%d", res);
    return 0;
}
