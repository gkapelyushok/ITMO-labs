#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int solution () {
    int n, W;
    cin >> n >> W;
    vector<int> cnt(20, 0);
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        cnt[log2(tmp)]++;
    }
    int result = 0;
    int not_used = n;
    while (not_used > 0) {
        int cur_W = W;
        int pow_W = (int)log2(W);
        while (pow_W >= 0) {
            pow_W = min(19, pow_W);
            if (cnt[pow_W] != 0) {
                cnt[pow_W]--;
                cur_W -= pow(2, pow_W);
                pow_W = (int)log2(cur_W);
                not_used--;
            } else {
                pow_W--;
            }
        }
        result++;
    }
    return result;
}
int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cout << solution() << endl;
    }
    return 0;
}
