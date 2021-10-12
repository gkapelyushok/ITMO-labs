#include <iostream>
#include <vector>
#include <cstdlib>


using namespace std;

int main() {
    vector <long long> a;
    string s;
    getline(cin, s);
    int i = 0;
    while (i < s.size()) {
        string type = "";
        while (s[i] == ' ') {
            i++;
        }
        if (s[i] == '+' || s[i] == '*' || s[i] == '-') {
            type = s[i++];
        } else {
            int j = 0;
            while (s[i] != ' ') {
                type[j++] = s[i++];
            }
        }
        if (type == "+") {
            long long x = a.back();
            a.pop_back();
            long long y = a.back();
            a.pop_back();
            a.push_back(x + y);
        } else if (type == "-") {
            long long x = a.back();
            a.pop_back();
            long long y = a.back();
            a.pop_back();
            a.push_back(y - x);
        } else if (type == "*") {
            long long x = a.back();
            a.pop_back();
            long long y = a.back();
            a.pop_back();
            a.push_back(y * x);
        } else {
            long long x = stoll(type);
            a.push_back(x);
        }
    }
    cout << a.front();
    return 0;
}
