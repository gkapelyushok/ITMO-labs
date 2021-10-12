#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, sum = 0;
	cin >> n;
	vector<long long> nums(10);
	vector<long long> prev(10, 1);
    if (n == 1) {
        cout << 8;
        return 0;
    }
	for (int i = 1; i < n; i++) {
		nums[0] = (prev[4] + prev[6]) % 1000000000;
		nums[1] = (prev[8] + prev[6]) % 1000000000;
		nums[2] = (prev[7] + prev[9]) % 1000000000;
        nums[3] = (prev[8] + prev[6]) % 1000000000;
		nums[4] = (prev[3] + prev[9] + prev[0]) % 1000000000;
        nums[6] = (prev[3] + prev[9] + prev[0]) % 1000000000;
		nums[7] = (prev[2] + prev[6]) % 1000000000;
		nums[8] = (prev[1] + prev[3]) % 1000000000;
        nums[9] = (prev[2] + prev[6]) % 1000000000;
		nums[0] = (prev[4] + prev[6]) % 1000000000;
		for (int j = 0; j < 10; j++) {
            prev[j] = nums[j];
        }
	}
	for (int i = 0; i < 10; i++) {
		if (i != 0 && i != 8 && i != 5) {
			sum = (sum + nums[i]) % 1000000000;
		}
	}
	cout << sum;
	return 0;
}
