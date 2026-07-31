#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		long long n;
		cin >> n;

		bool found = false;
		for (long long a = 0; a <= 9; a++) {
			long long b = n - a;

			if (b >= 0 && b % 12 == 0) {
				cout << a << " " << b << "\n";
				found = true;
				break;
			}
		}
		if (!found) {
			long long a = 11;
			long long b = n - a;

			if (b >= 0 && b % 12 == 0) {
				cout << a << " " << b << "\n";
				found = true;
			}
		}
		if (!found) {
			long long a = 22;
			long long b = n - a;

			if (b >= 0 && b % 12 == 0) {
				cout << a << " " << b << "\n";
				found = true;
			}
		}

		if (!found)
			cout << -1 << "\n";
	}

	return 0;
}
