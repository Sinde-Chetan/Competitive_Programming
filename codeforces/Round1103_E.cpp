#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto &x : a)
            cin >> x;
        unordered_map<int, unordered_set<int>> seen;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int mn = a[i];
            int mx = a[i];
            unordered_set<int> used;
            for (int j = i; j < n; j++) {
                if (used.count(a[j])) break;
                used.insert(a[j]);
                mn = min(mn, a[j]);
                mx = max(mx, a[j]);
                int len = j - i + 1;
                if (mx - mn + 1 == len) {
                    if (seen[len].count(mx - len) || seen[len].count(mx + len)) {
                        ans = max(ans, len);
                    }
                    seen[len].insert(mx);
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
