#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;

  set<int> u;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    u.insert(x);
  }
  cout << u.size();
}
