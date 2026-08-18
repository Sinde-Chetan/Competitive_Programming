#include <bits/stdc++.h>

using namespace std;

bool checkprime(int p) {
  bool yes = true;
  for (int i = 2; i <= sqrt(p); i++) {
    if (p % i == 0) {
      yes = false;
      break;
    }
  }

  return yes;
}

int main() {

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    if (checkprime(n + 1))
      cout << "YES" << "\n";
    else
      cout << "NO\n";
  }
}
