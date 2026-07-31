#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;
	string s;
	cin >> s;

	set<int> st, ans;
	for (int i = 0; i < m; i++) {
		int v;
		cin >> v;
		st.insert(v);
		ans.insert(v);
	}

	int cnt = 0;
	for (char c : s) {
		if (c == 'B') cnt++;
	}
	list<int> w;
	int cur = 1;
	int lim = 2 * cnt + 5;

	while ((int)w.size() < lim) {
		if (st.find(cur) == st.end()) {
			w.push_back(cur);
		}
		cur++;
	}

	for (int len = 1; len <= n; len++) {
		int p = 1;
		for (int i = 0; i < len; i++) {
			if (s[i] == 'A') {
				p++;
			} else {
				auto it = upper_bound(w.begin(), w.end(), p);
				if (it != w.end()) {
					p = *it;
				} else {
					p++;
				}
			}
		}

		if (ans.find(p) == ans.end()) {
			ans.insert(p);
			w.remove(p);
		}
	}

	cout << ans.size() << "\n";
	for (auto it = ans.begin(); it != ans.end(); ++it) {
		cout << *it << (next(it) == ans.end() ? "" : " ");
	}
	cout << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
