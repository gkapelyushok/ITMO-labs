#include <iostream>
#include <vector>
using namespace std;
 
int main() {
    int n;
    cin >> n;
    vector<int> cnt(101);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }
    for (int i = 0; i < 101; i++) {
        for (int j = 0; j < cnt[i]; j++) {
            cout << i << " ";
        }
    }
    return 0;
}
