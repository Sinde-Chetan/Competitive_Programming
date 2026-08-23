#include <bits/stdc++.h>

using namespace std;

int main() {

  double n;
  cin >> n;
  vector<double> a(n + 1);

  for (int i = 1; i <= n; i++)
    cin >> a[i];
  vector<double> exp(n + 1);
  double sum_tot = 0;
  for (int i = 1; i <= a[n]; i++) {
    sum_tot += i;
  }
  exp[n] = sum_tot / a[n];
  for (int i = n - 1; i >= 1; i--) {
    if (a[i] <= exp[i + 1]) {
      exp[i] = exp[i + 1];
      continue;
    }

    else if (a[i] > exp[i + 1]) {
      long long extra = exp[i + 1] / 1;
      double sum = (a[i] - extra) * (a[i] - extra + 1) / 2;
      exp[i] = (extra * (exp[i + 1]) + (a[i] - extra) * extra + sum) / a[i];
    }
  }
  cout << exp[1] << "\n";
}
