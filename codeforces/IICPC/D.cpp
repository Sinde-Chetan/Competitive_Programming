#include <bits/stdc++.h>

using namespace std;

void paths(long long &tot, long long &sum, long long a, long long b,
           long long c, long long n) {
  if (a == n && b == n && c == n) {
    sum += a * b + b * c + c * a;
    tot++;
    return;
  }

  if (a < n) {
    sum += (a + 1) * b + b * c + (a + 1) * c;
    paths(tot, sum, a + 1, b, c, n);
  }
  if (b + 1 <= n) {
    sum += a * (b + 1) + (b + 1) * c + a * c;
    paths(tot, sum, a, b + 1, c, n);
  }

  if (c + 1 <= n) {
    sum += a * b + b * (c + 1) + (c + 1) * a;
    paths(tot, sum, a, b, c + 1, n);
  }
}

int main() {

  const long long MOD = 998244353;

  int t;
  cin >> t;
  while (t--) {

    long long n;
    cin >> n;

    long long sum = 0;
    long long tot = 0;

    paths(tot, sum, 0, 0, 0, n);

    long long res = (sum / tot) % MOD;

    cout << sum << " " << tot << "\n";
  }
}
