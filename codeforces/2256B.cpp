#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    string s;
    cin >> s;

    int ans = 1;

    // Check both parity subsequences: even positions and odd positions
    for (int st = 0; st < 2; st++) {
      bool yes0 = true; // Pattern starts with 0
      bool yes1 = true; // Pattern starts with 1
      int cnt = 0;

      for (int i = st; i < n; i += 2) {
        char need0 = (cnt % 2 == 0 ? '0' : '1');
        char need1 = (cnt % 2 == 0 ? '1' : '0');

        if (s[i] != '?' && s[i] != need0)
          yes0 = false;

        if (s[i] != '?' && s[i] != need1)
          yes1 = false;

        cnt++;
      }

      int ways = 0;
      if (yes0)
        ways++;
      if (yes1)
        ways++;

      ans *= ways;
    }

    cout << ans << "\n";
  }

  return 0;
}
