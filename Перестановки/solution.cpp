#include <iostream>

using namespace std;

int n;
void gen(string prefix) {
    if (prefix.size() == 2 * n) {
        cout << prefix << endl;
        return;
    }

    for (int i = n; i >= 1; i--) {
        if (prefix.find(to_string(i)) == string::npos) {
            gen(prefix + to_string(i) + " ");
        }
    }
}

int main() {
    cin >> n;
    gen("");
    return 0;
}
