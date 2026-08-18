#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    vector<long long> a(2 * n);
    for (auto &x : a)
      cin >> x;
    long long sum = 0;

    vector<long long> left(n + 1, -1);
    vector<long long> right(n + 1, -1);

    for (int i = 0; i < 2 * n; i++) {
      if (left[a[i] == -1])
        left[a[i]] = i;
      else
        right[a[i]] = i;
    }
  }
  cout << sum << "\n";
}
}
