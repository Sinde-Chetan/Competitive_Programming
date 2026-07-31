
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> w(n);
    for (auto &x : w)
      cin >> x;
    if ((n & 1)) {
      cout << "NO\n";
      continue;
    }
    if (w[0] < w[n - 1] || w[0] - w[n - 1] <= 1) {
      cout << "NO\n";
      continue;
    }
    int low = 0;
    int high = INT_MAX;

    for (int i = 0; i < n; i++) {
      if (i % 2 == 0) {
        high = min(high, w[i]);
      } else {
        low = max(low, w[i]);
      }
    }

    if (low + 1 < high)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}
