#include <bits/stdc++.h>

using namespace std;

int main() {
  int TestsNumT;
  cin >> TestsNumT;

  while (TestsNumT--) {
    int n;
    cin >> n;

    vector<int> a(n);
    for (auto &x : a)
      cin >> x;

    vector<pair<int, int>> runs;

    for (int x : a) {
      if (runs.empty() || runs.back().first != x) {
        runs.push_back({x, 1});
      } else {
        runs.back().second++;
      }
    }

    int m = runs.size();
    int ans = m;

    for (int i = 0; i + 1 < m; i++) {
      if (runs[i].second >= 2 && runs[i + 1].second >= 2) {
        ans = max(ans, m + 2);
      }
    }

    for (int i = 0; i < m; i++) {
      if (runs[i].second < 2)
        continue;

      int x = runs[i].first;

      bool left = false;
      bool right = false;

      if (i >= 1) {
        if (i - 2 < 0 || runs[i - 2].first != x) {
          left = true;
        }
      }

      if (i + 1 < m) {
        if (i + 2 >= m || runs[i + 2].first != x) {
          right = true;
        }
      }

      if (left || right) {
        ans = max(ans, m + 1);
      }
    }

    cout << ans << '\n';
  }

  return 0;
}
