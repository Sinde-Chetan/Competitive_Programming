#include<bits/stdc++.h>
using namespace std;

int main() {

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        vector<long long> a(n);

        for (int i = 0; i < n; i++)
            cin >> a[i];

        vector<long long> L(n), R(n);

        L[0] = min(a[0], 1LL);

        for (int i = 1; i < n; i++)
            L[i] = min(a[i], L[i - 1] + 1);

        R[n - 1] = min(a[n - 1], 1LL);

        for (int i = n - 2; i >= 0; i--)
            R[i] = min(a[i], R[i + 1] + 1);

        bool ok = false;

        for (int i = 0; i < n; i++) {
            if (min(L[i], R[i]) >= max(i + 1, n - i)) {
                ok = true;
                break;
            }
        }

        cout << (ok ? "Yes\n" : "No\n");
    }
}
