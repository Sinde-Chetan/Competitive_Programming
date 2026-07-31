#include <bits/stdc++.h>
using namespace std;

int main() {

	int T;
	cin >> T;

	while (T--) {
		int n;
		cin >> n;

		vector<int> a(n + 1);
		for (int i = 1; i <= n; i++)
			cin >> a[i];

		vector<int> dp(n + 1, 0);
		vector<int> best(n + 1, INT_MIN);

		for (int i = 1; i <= n; i++) {
			dp[i] = dp[i - 1];

			if (best[a[i]] != INT_MIN) {
				dp[i] = max(dp[i], best[a[i]] + i + 1);
			}

			best[a[i]] = max(best[a[i]], dp[i - 1] - i);
		}

		cout << dp[n] << "\n";
	}

	return 0;
}
