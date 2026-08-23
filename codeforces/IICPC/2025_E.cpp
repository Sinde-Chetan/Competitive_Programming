#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

const long long MOD = 1e9 + 7;

struct Fraction {
  long long p;
  long long q;
};

map<long long, Fraction> memo;

Fraction add_fractions(Fraction f1, Fraction f2) {
  long long max_q = max(f1.q, f2.q);

  long long p1 = f1.p;
  for (int i = 0; i < max_q - f1.q; ++i)
    p1 *= 3;

  long long p2 = f2.p;
  for (int i = 0; i < max_q - f2.q; ++i)
    p2 *= 3;

  return {p1 + p2, max_q};
}

Fraction prob(long long D0) {
  if (D0 < 0)
    return {0, 0};
  if (D0 == 0)
    return {1, 0};
  if (memo.count(D0))
    return memo[D0];

  Fraction result;

  if (D0 & 1) {
    Fraction res = prob((D0 + 1) / 2);
    result = {res.p, res.q + 1};
  } else {
    if (D0 == 2) {
      Fraction res1 = prob(1);
      result = {res1.p, res1.q + 1};
    } else {
      Fraction sum = add_fractions(prob(D0 / 2), prob(D0 / 2 - 1));
      result = {sum.p, sum.q + 1};
    }
  }

  while (result.p > 0 && result.p % 3 == 0) {
    result.p /= 3;
    result.q--;
  }

  return memo[D0] = result;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  if (!(cin >> t))
    return 0;

  while (t--) {
    long long K;
    cin >> K;

    long long D0 = (K - 1) / 2;
    Fraction ans = prob(D0);

    cout << (ans.p + ans.q) % MOD << "\n";
  }

  return 0;
}
