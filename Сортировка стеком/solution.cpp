#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> stack;
    vector<int> sorted_a;
    vector<int> res;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        while (!stack.empty() && stack.back() < a[i]) {
            res.push_back(0);
            sorted_a.push_back(stack.back());
            stack.pop_back();
        }
        stack.push_back(a[i]);
        res.push_back(1);
    }
    while (!stack.empty()) {
        sorted_a.push_back(stack.back());
        res.push_back(0);
        stack.pop_back();
    }
    for (int i = 1; i < n; i++) {
        if (sorted_a[i] < sorted_a[i - 1]) {
            cout << "impossible" << endl;
            return 0;
        }
    }
    for (int i = 0; i < res.size(); i++) {
        if (res[i] == 0) {
            cout << "pop" << endl;
        } else {
            cout << "push" << endl;
        }
    }
    return 0;
}
