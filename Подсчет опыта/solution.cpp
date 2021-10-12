#include <iostream>
#include <vector>

using namespace std;

struct unit {
    int value;
    int exp;
    int rank;
};

vector<unit> a;

int get(int x) {
    while (x != a[x].value) {
        x = a[x].value;
    }
    return x;

}
int getExp(int x) {
    int exp = 0;
    while (a[x].value != x) {
        exp += a[x].exp;
        x = a[x].value;
    }
    exp += a[x].exp;
    return exp;
}

void join(int x, int y) {
    x = get(x);
    y = get(y);
    if (x == y) {
        return;
    }
    if (a[x].rank > a[y].rank) {
        int tmp = x;
        x = y;
        y = tmp;
    }
    if (a[x].rank == a[y].rank) {
        a[y].rank++;
    }
    a[x].value = y;
    a[x].exp -= a[y].exp;

}
void add(int x, int exp) {
    x = get(x);
    a[x].exp += exp;
}

int main() {
    int n;
    cin >> n;
    a.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        a[i].value = i;
        a[i].exp = 0;
        a[i].rank = 0;
    }
    int m;
    cin >> m;
    string type;
    for (int i = 0; i < m; i++) {
        cin >> type;
        if (type == "join") {
            int x, y;
            cin >> x >> y;
            join(x, y);
        } else if (type == "add") {
            int x, exp;
            cin >> x >> exp;
            add(x, exp);
        } else if (type == "get") {
            int x;
            cin >> x;
            cout << getExp(x) << endl;
        }
    }
    return 0;
}
