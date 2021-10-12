#include <iostream>
#include <vector>
#include <string>
using namespace std;

int n, k;
vector<int> a;
void gen(const string& s) {
    if (s.size() == 2 * n) {
        cout << s << endl;
        return;
    }
    for (int j = 0; j < k; j++) {
        gen(s + to_string(j) + " ");
    }
}

int main() {
    cin >> n >> k;
    a.resize(k);
    for (int i = 0; i < k; i++) {
        a[i] = i;
    }
    gen("");
    return 0;
}
