#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void solve() {
    string a, b;
    cin >> a >> b;
    int n = a.size(), m = b.size();

    vector<int> pA(n + 1, 0), pB(m + 1, 0);
    for (int i = 0; i < n; i++) pA[i + 1] = (pA[i] + (a[i] - '0')) % 10;
    for (int i = 0; i < m; i++) pB[i + 1] = (pB[i] + (b[i] - '0')) % 10;

    if (pA[n] != pB[m]) {
        cout << -1 << endl;
        return;
    }

    // dp[i][j] = max segments using a[0...i-1] and b[0...j-1]
    // Initialized to -1e9 to represent unreachable states
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1e9));
    dp[0][0] = 0;

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (dp[i][j] < 0) continue;
            // Transition: try all next points where prefix sums match
            for (int ni = i + 1; ni <= n; ni++) {
                for (int nj = j + 1; nj <= m; nj++) {
                    if (pA[ni] == pB[nj]) {
                        dp[ni][nj] = max(dp[ni][nj], dp[i][j] + 1);
                    }
                }
            }
        }
    }
    cout << dp[n][m] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
