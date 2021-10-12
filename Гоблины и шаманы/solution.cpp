 #include <iostream>
 #include <deque>

using namespace std;

struct queue {
    deque<int> left, right;

    void fix() {
        if (left.empty() && !right.empty()) {
            left.push_back(right.front());
            right.pop_front();
        } else if (right.size() > left.size()) {
            left.push_back(right.front());
            right.pop_front();
        }
    }

    void push_back(int x) {
        right.push_back(x);
        fix();
    }
    void push_mid(int x) {
        right.push_front(x);
        fix();
    }
    void pop() {
        cout << left.front() << endl;
        left.pop_front();
        fix();
    }
};

int main() {
    int n;
    cin >> n;
    queue q;
    for (int i = 0; i < n; i++) {
        char type;
        cin >> type;
        if (type == '-') {
            q.pop();
        } else if (type == '+') {
            int x;
            cin >> x;
            q.push_back(x);
        } else if (type == '*') {
            int x;
            cin >> x;
            q.push_mid(x);
        }
    }
    return 0;
}
