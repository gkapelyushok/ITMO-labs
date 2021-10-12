#include <iostream>
#include <vector>

using namespace std;

struct unit {
    int value;
    int min;
    int max;
    int size;
};

vector<unit> a;

int get(int x) {
    int preds = x;
    while (preds != a[preds].value) {
        preds = a[preds].value;
    }
    while (x != preds) {
        x = a[x].value;
        a[x].value = preds;
    }
    return preds;
}

void join(int x, int y) {
    x = get(x);
    y = get(y);
    if (x == y) {
        return;
    }
    if (a[x].size > a[y].size) {
        int tmp = x;
        x = y;
        y = tmp;
    }
    a[x].value = y;
    a[y].min = min(a[x].min, a[y].min);
    a[y].max = max(a[x].max, a[y].max);
    a[y].size += a[x].size;
}

int main() {
    int n;
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        a[i].value = a[i].min = a[i].max = i;
        a[i].size = 1;
    }
    string type;
    while (cin >> type) {
        if (type == "union") {
            int x, y;
            cin >> x >> y;
            join(x - 1, y - 1);
        } else if (type == "get") {
            int x;
            cin >> x;
            x = get(x - 1);
            cout << a[x].min + 1<< " "
                 << a[x].max + 1<< " "
                 << a[x].size << endl;
        }
    }
    return 0;
}
