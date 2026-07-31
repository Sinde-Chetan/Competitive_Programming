#include <bits/stdc++.h>
using namespace std;

int main() {

	int T;
	cin >> T;

	while (T--) {

		int n;
		cin >> n;

		vector<long long> a(n);

		for (auto &x : a)
			cin >> x;

		long long cur = a[0];
		long long ans = cur;

		for (int i = 1; i < n; i++) {

			if (a[i] < cur)
				cur += a[i];
			else
				cur = a[i];

			ans = max(ans, cur);
		}

		cout << ans << "\n";
	}
}
