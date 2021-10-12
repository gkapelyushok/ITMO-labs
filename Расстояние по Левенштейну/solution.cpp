#include <iostream>
#include <vector>

using namespace std;

int min(int a, int b, int c) {
    return min(a, min(b, c));
}

int m(char a, char b) {
    if (a == b) {
        return 0;
    }
    return 1;
}


int main() {
    string string1, string2;
    cin >> string1 >> string2;
    vector<vector<int>> dp(string1.size() + 1, vector<int>(string2.size() + 1));
    for (int i = 0; i < string1.size() + 1; i++) {
        for (int j = 0; j < string2.size() + 1; j++) {
            if (j == 0 && i == 0) {
                dp[i][j] = 0;
            } else if (j == 0 && i > 0) {
                dp[i][j] = i;
            } else if (i == 0 && j > 0) {
                dp[i][j] = j;
            } else {
                dp[i][j] = min(dp[i][j - 1] + 1,
                               dp[i - 1][j] + 1,
                               dp[i - 1][j - 1] + m(string1[i - 1], string2[j - 1]));
            }
        }
    }
    cout << dp[string1.size()][string2.size()];
    return 0;
}
