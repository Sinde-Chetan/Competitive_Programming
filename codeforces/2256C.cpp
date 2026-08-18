#include <bits/stdc++.h>

using namespace std;

int main() {

  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    int red = 0;
    int blue = 0;

    for (int i = 0; i < s.size() - 1; i++) {
      if (!(i & 1)) {
        if (s[i] == '1' && s[i + 1] == '0')
          blue++;
        else if (s[i] == '1' && s[i + 1] == '1')
          red++;
      } else {
        if (s[i] == '1' && s[i + 1] == '0')
          red++;
        else if (s[i] == '1' && s[i + 1] == '1')
          blue++;
      }
    }
    if (s[2 * n - 1] == '1' && s[0] == '1')
      blue++;
    else if (s[2 * n - 1] == '1' && s[0] == '0')
      red++;

    cout << blue << " " << red << "\n";
  }
}
