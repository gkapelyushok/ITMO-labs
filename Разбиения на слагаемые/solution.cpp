#include <iostream>
#include <vector>

using namespace std;

int n;

void gen(vector<int> prefix, int sum, int prev) {
    if (sum >= n) {
        if (sum == n) {
            for (int i = 0; i < prefix.size(); i++) {
                cout << prefix[i] << " ";
            }
            cout << "\n";
        }
        return;
    }

    for (int i = 1; i <= prev; i++) {
        vector<int> a = prefix;
        a.push_back(i);
        gen(a, sum + i, i);
    }
}

int main() {
    cin >> n;
    gen({}, 0, n + 1);
    return 0;
}
