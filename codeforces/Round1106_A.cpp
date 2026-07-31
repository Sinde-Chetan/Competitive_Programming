#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, c;
		cin >> n >> c;
		vector<int> a(n);
		vector<int> b(n);
		for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = 0; i < n; i++) cin >> b[i];
		long long cost1 = 0; 
		bool possible1 = true;
		for (int i = 0; i < n; i++) {
			if (a[i] < b[i]) {
				possible1 = false;
			}
			cost1 += (a[i] - b[i]);
		}
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		long long cost2 = c; 
		bool possible2 = true;
		for (int i = 0; i < n; i++) {
			if (a[i] < b[i]) {
				possible2 = false;
			}
			cost2 += (a[i] - b[i]);
		}
		if (possible1 && possible2) {
			cout << min(cost1, cost2) << "\n";
		} 
		else if (possible2) {
			cout << cost2 << "\n";
		} 
		else {
			cout << "-1\n";
		}
	}

	return 0;
}
