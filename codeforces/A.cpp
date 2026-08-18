#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int n = s.size();
    bool removed0 = false, removed1 = false;

    for (int i = 0; i < s.size(); i++) {
      if (!removed0 && s[i] == '0') {
        s.erase(i, 1);
        removed0 = true;
        i--; // adjust because string shrank
      } else if (!removed1 && s[i] == '1') {
        s.erase(i, 1);
        removed1 = true;
        i--;
      }

      if (removed0 && removed1)
        break;
    }
    cout << s << "\n";
  }
}
