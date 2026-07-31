#include <bits/stdc++.h>
using namespace std;

int main() {
	int k;
	cin >> k;

	map<long long, pair<int, int>> mp;

	for (int seq = 1; seq <= k; seq++) {
		int n;
		cin >> n;

		vector<int> a(n);
		long long sum = 0;

		for (int i = 0; i < n; i++) {
			cin >> a[i];
			sum += a[i];
		}

		for (int i = 0; i < n; i++) {
			long long rem = sum - a[i];

			if (mp.count(rem) && mp[rem].first != seq) {
				cout << "YES\n";
				cout << mp[rem].first << " "<< mp[rem].second << "\n";
				cout << seq << " "<< i + 1 << "\n";
				return 0;
			}
		}
		for (int i = 0; i < n; i++) {
			long long rem = sum - a[i];

			if (!mp.count(rem)) mp[rem] = {seq, i + 1};
		}
	}

	cout << "NO\n";
}
