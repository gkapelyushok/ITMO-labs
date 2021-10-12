#include <iostream>
#include <vector>

using namespace std;

int n;

void gen(string s, int prev) {
    if (s.size() == 2*n) {
        cout << s << endl;
        return;
    }
    gen(s + '0' + " ", 0);
    if (prev != 1) {
        gen(s +  '1' + " ", 1);
    }
}

int main() {
    cin >> n;
    gen("", 0);
    return 0;
}
