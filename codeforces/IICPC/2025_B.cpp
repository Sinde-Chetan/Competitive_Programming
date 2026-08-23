#include <bits/stdc++.h>

using namespace std;

int main() {

  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    float ans = 0;

    for (float i = 1; i <= n; i++) {
      ans += 1 / i;
    }
    int x = ans;

    cout << x << "\n";
  }
}
