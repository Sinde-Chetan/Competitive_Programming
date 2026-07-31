#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;

		vector<int> a(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];
		vector<int> dp(n + 1, 0);
		for (int i = n - 1; i >= 0; i--) {
			dp[i] = 1 + dp[i + 1];
			if (i + a[i] < n) {
				dp[i] = min(dp[i], dp[i + a[i] + 1]);
			}
		}

		cout << dp[0] << "\n";
	}
}
