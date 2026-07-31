#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, x;
  cin >> n >> x;
  vector<long long> a(n);
  for (auto &x : a)
    cin >> x;
  int l = 0;
  int sum = 0;
  int ans = 0;
  for (int r = 0; r < n; r++) {
    sum += a[r];

    while (sum > x) {
      sum -= a[l];
      l++;
    }
    if (sum == x)
      ans++;
  }
  cout << ans << "\n";
}
