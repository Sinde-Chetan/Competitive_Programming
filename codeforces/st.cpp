#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    int sx, sy;
    cin >> n >> sx >> sy;

    int right = 0, left = 0, up = 0, down = 0;

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;

        if (x > sx) right++;
        if (x < sx) left++;
        if (y > sy) up++;
        if (y < sy) down++;
    }

    int ans = right;
    int px = sx + 1, py = sy;

    if (left > ans) {
        ans = left;
        px = sx - 1;
        py = sy;
    }

    if (up > ans) {
        ans = up;
        px = sx;
        py = sy + 1;
    }

    if (down > ans) {
        ans = down;
        px = sx;
        py = sy - 1;
    }

    cout << ans << '\n';
    cout << px << ' ' << py << '\n';

    return 0;
}
