#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	if(!(cin >> t)) return 0;;

	while(t--){
		int n;
		if(!(cin >> n)) return 0;
		vector<int> a(n);
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		int good = 0;

		for(int i = 0; i < n-1; i++){
			int diff = abs(a[i] - a[i+1]);
			int g = gcd(a[i], a[i+1]);

			if(diff == g) good++;
		}
		cout << good << "\n";
	}
}
