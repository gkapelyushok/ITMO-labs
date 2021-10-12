#include <iostream>
#include <vector>

using namespace std;

int k,n;
void gen(vector<int> s, int prev) {
    if (s.size() == k) {
        for (int i = 0; i < k; i++) {
            cout << s[i] << " ";
        }
        cout << "\n";
        return;
    }
    for (int i = k - s.size(); i < prev; i++) {
        vector<int> a = s;
        a.push_back(i);
        gen(a, i);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> k >> n;
    gen({}, n + 1);
    return 0;
}
