#include <bits/stdc++.h>
using namespace std;

const int NEG = -1e9;

int main(){
	int T;
	cin >> T;
	while (T--) {
		int n, x, s;
		cin >> n >> x >> s;
		string u;
		cin >> u;
		vector<vector<int>> dp(x + 1,vector<int>(x * s + 1, NEG));
		dp[0][0] = 0;
		for (int i = 0; i < n; i++) {
			auto ndp = dp;
			for (int used = 0; used <= x; used++) {
				for (int free = 0; free <= x * s; free++) {
					if (dp[used][free] < 0)
						continue;
					int cur = dp[used][free];
					ndp[used][free] = max(ndp[used][free], cur);
					if (u[i] == 'I') {
						if (used < x)
							ndp[used + 1][free + s - 1] = max(ndp[used + 1][free + s - 1],cur + 1);
					}
					else if (u[i] == 'E'){
						if (free > 0)
							ndp[used][free - 1] = max(ndp[used][free - 1],cur + 1);
					}
					else {
						if (free > 0) ndp[used][free - 1] = max(ndp[used][free - 1],cur + 1);
						if (used < x) ndp[used + 1][free + s - 1] = max(ndp[used + 1][free + s - 1],cur + 1);
					}
				}
			}
			dp = move(ndp);
		}
		int ans = 0;
		for (auto &v : dp)
			for (int x : v)
				ans = max(ans, x);
		cout << ans << "\n";
	}
}
