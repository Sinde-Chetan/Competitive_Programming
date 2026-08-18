#include <bits/stdc++.h>

using namespace std;

int main() {

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<pair<char, int>> cont;

    int len = 1;
    for (int i = 1; i < n; i++) {
      if (s[i] == s[i - 1])
        len++;
      else {
        cont.push_back({s[i - 1], len});
        len = 1;
      }
    }
    cont.push_back({s[n - 1], len});
    int groups = cont.size();

    bool reduce2 = false;
    bool reduce1 = false;

    for (int i = 1; i < groups - 1; i++) {
      if (cont[i].second == 1) {

        reduce1 = true;
        if (cont[i - 1].first == cont[i + 1].first) {
          reduce2 = true;
        }
      }
    }

    if (reduce2)
      cout << groups - 2 << '\n';
    else if (reduce1)
      cout << groups - 1 << '\n';
    else
      cout << groups << '\n';
  }
}
