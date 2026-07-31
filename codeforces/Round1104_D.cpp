#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        string s;
        cin >> s;

        long long ans = 0;
        int last = -1;

        for (int i = 0; i < n; i++) {
            if (i > 0 && s[i] == s[i - 1])
                last = i - 1;

            ans += last + 2; // count beautiful substrings ending at i
        }

        cout << ans << "\n";
    }
}
