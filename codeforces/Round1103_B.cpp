#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {

		int n, k;
		cin >> n >> k;

		string s;
		cin >> s;

		bool possible = true;

		for (int start = 0; start < k; start++) {

			int ones = 0;

			for (int i = start; i < n; i += k) {
				if (s[i] == '1')
					ones++;
			}

			if (ones % 2) {
				possible = false;
				break;
			}
		}

		cout << (possible ? "YES\n" : "NO\n");
	}

	return 0;
}
