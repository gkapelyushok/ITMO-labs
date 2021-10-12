#include <iostream>
#include <vector>
 
using namespace std;
 
int main() {
    int n;
    scanf("%d", &n);
    vector<int> a;
    for (int i = 0; i < n; i++) {
        int type;
        scanf("%d", &type);
        if (type == 1) {
            int id;
            scanf("%d", &id);
            a.push_back(id);
        }
        if (type == 2) {
            a.erase(a.begin());
        }
        if (type == 3) {
            a.pop_back();
        }
        if (type == 4) {
            int q;
            scanf("%d", &q);
            int j = 0;
            while (a[j] != q) {
                j++;
            }
            printf("%d\n", j);
        }
        if (type == 5) {
            printf("%d\n", a.front());
        }
    }
    return 0;
}
