#include <iostream>
#include <vector>

using namespace std;

int n, k;

void gen(string s, int cnt) {
    if (s.size() == 2 * n) {
        if (cnt == k) {
            cout << s << endl;
        }
        return;
    }
    if (cnt == k) {
        gen(s + '0' + " ", cnt);
    } else if (s.size()/2 - cnt == n - k) {
        gen(s + '1' + " ", cnt + 1);
    } else if (cnt < k && s.size()/2 - cnt < n - k) {
        gen(s + '0' + " ", cnt);
        gen(s + '1' + " ", cnt + 1);
    }
}

int main() {

    cin >> n >> k;
    gen("", 0);
    return 0;
}
