#include <bits/stdc++.h>

using namespace std;

int main() {

  int t;
  cin >> t;
  while (t--) {

    long long k;
    cin >> k;
    vector<long long> dp(k + 2, 0);
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;

    for (int i = 4; i < k + 1; i++) {
      dp[i] = dp[i - 3] + dp[i - 3];
    }
    const long long div = 1000000009;

    if (k == 2)
      cout << "3\n";
    else
      cout << (dp[k] + dp[k - 2] + dp[k - 2]) % div << "\n";
  }
}
