#include <bits/stdc++.h>
using namespace std;

const int MAXA = 1000000;
int min_prime[MAXA + 1];
int max_prime[MAXA + 1];

void sieve() {
	for (int i = 2; i <= MAXA; i++) {
		if (min_prime[i] == 0) {
			for (int j = i; j <= MAXA; j += i) {
				if (min_prime[j] == 0) {
					min_prime[j] = i;
				}
				max_prime[j] = i;
			}
		}
	}
}

int count_prime_factors(int num) {
	int count = 0;
	while (num > 1) {
		count++;
		num /= min_prime[num];
	}
	return count;
}

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	bool is_sorted = true;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (i > 0 && a[i] < a[i - 1]) {
			is_sorted = false;
		}
	}

	if (is_sorted) {
		cout << "Bob\n";
		return;
	}

	for (int i = 0; i < n - 1; i++) {
		if (a[i] > a[i + 1]) {
			int max_left = max_prime[a[i]];
			int min_right = (a[i + 1] == 1) ? 2e9 : min_prime[a[i + 1]];

			if (max_left > min_right) {
				cout << "Alice\n";
				return;
			}
		}
	}

	long long total_splits = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] > 1) {
			total_splits += (count_prime_factors(a[i]) - 1);
		}
	}

	if (total_splits % 2 == 1) {
		cout << "Alice\n";
	} else {
		cout << "Bob\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	sieve();

	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
