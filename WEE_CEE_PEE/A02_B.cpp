#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        long long n;
        cin >> n;
        long long x = 0, y = 0;
        long long p = 1;
        bool turn = false;
        while (n) {
            int d = n % 10;

            if (d % 2 == 0) {
                x += (d / 2) * p;
                y += (d / 2) * p;
            } else {
                if (!turn) {
                    x += (d / 2) * p;
                    y += (d / 2 + 1) * p;
                } else {
                    x += (d / 2 + 1) * p;
                    y += (d / 2) * p;
                }
                turn = !turn;
            }
            p *= 10;
            n /= 10;
        }

        cout << x << ' ' << y << '\n';
    }
}
