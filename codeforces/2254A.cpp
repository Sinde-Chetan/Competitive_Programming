#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

int main() {

  int t;
  cin >> t;
  while (t--) {

    vector<int> a(3);

    for (auto &x : a)
      cin >> x;

    sort(a.begin(), a.end());

    cout << min(a[1] - a[0], a[2] - a[1]) << "\n";
  }
}
