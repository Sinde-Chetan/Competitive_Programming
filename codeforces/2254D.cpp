#include <bits/stdc++.h>
#include <iterator>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vector<long long> b(n);

    for (auto &x : b)
      cin >> x;

    map<long long, int> count;

    for (int i = 0; i < n; i++)
      count[b[i]]++;

    if (!count.count(0)) {
      cout << "-1\n";
      continue;
    }

    bool ok = true;
    map<long long, long long> toins;

    for (auto it = count.begin(); it != prev(count.end()); it++) {
      auto it2 = next(it);

      long long x = (it2->first - it->first) % it->second;
      long long y = (it2->first - it->first) / it->second;

      if (x != 0) {
        ok = false;
        break;
      }

      if (!toins.empty() && y <= prev(toins.end())->second) {
        ok = false;
        break;
      }

      toins[it->first] = y;
    }

    if (ok) {
      if (count.size() == 1) {
        toins[prev(count.end())->first] = 1;
      } else {
        toins[prev(count.end())->first] = prev(toins.end())->second + 1;
      }
    }

    if (ok) {
      for (int i = 0; i < n; i++)
        b[i] = toins[b[i]];

      for (auto x : b)
        cout << x << " ";

      cout << "\n";
    } else {
      cout << "-1\n";
    }
  }
}
