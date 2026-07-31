#include <bits/stdc++.h>
using namespace std;

long long solve(long long a, long long b, long long x) {
	if (a == b)
		return 0;

	if (a < b)
		swap(a, b);

	long long ans = a - b;
	ans = min(ans,
			1 + solve(a / x, b, x));

	return ans;
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		long long a, b, x;
		cin >> a >> b >> x;

		cout << solve(a, b, x) << "\n";
	}
}
