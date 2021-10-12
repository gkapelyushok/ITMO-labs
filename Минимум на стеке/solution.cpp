#include <iostream>
#include <vector>

using namespace std;


int main() {
    int n;
    cin >> n;
    vector<long long> a;
    vector<long long> min;
    for (int i = 0; i < n; i++) {
        int t;
        scanf("%d", &t);
        if (t == 1) {
            long long x = 0;
            scanf("%lld", &x);
            a.push_back(x);
            if (min.empty() || min.back() > x) {
                min.push_back(x);
            } else {
                min.push_back(min.back());
            }
        } else if (t == 2) {
            a.pop_back();
            min.pop_back();
        } else {
            printf("%lld\n", min.back());
        }

    }
    return 0;
}
