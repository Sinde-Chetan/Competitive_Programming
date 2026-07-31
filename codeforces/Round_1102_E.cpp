#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;

    vector<long long> h(n);
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
    }

    // Since the vessels are circular, duplicate the array to easily handle paths
    vector<long long> h2(2 * n);
    for (int i = 0; i < 2 * n; ++i) {
        h2[i] = h[i % n];
    }

    // f[i][0] will store the bottleneck running clockwise
    // f[i][1] will store the bottleneck running counter-clockwise
    // We precompute running minimums from both directions
    vector<long long> left_min(2 * n), right_min(2 * n);

    // To compute this efficiently for every pair, we can think about the 
    // capacity between an empty vessel l and destination vessel j.
    // Let's implement a clean linear scan approach.
    
    vector<long long> ans(n, 0);

    for (int l = 0; l < n; ++l) {
        long long total_water = 0;
        
        // Clockwise bottleneck tracking
        long long current_bottleneck = 2e18; // Infinity
        vector<long long> cw_val(n, 0);
        for (int step = 1; step < n; ++step) {
            int current_vessel = (l + step) % n;
            int barrier_idx = (l + step - 1) % n;
            current_bottleneck = min(current_bottleneck, h[barrier_idx]);
            cw_val[current_vessel] = current_bottleneck;
        }

        // Counter-clockwise bottleneck tracking
        current_bottleneck = 2e18;
        vector<long long> ccw_val(n, 0);
        for (int step = 1; step < n; ++step) {
            int current_vessel = (l - step + n) % n;
            int barrier_idx = current_vessel;
            current_bottleneck = min(current_bottleneck, h[barrier_idx]);
            ccw_val[current_vessel] = current_bottleneck;
        }

        // The capacity of each vessel is the maximum allowed by either path
        for (int j = 0; j < n; ++j) {
            if (j == l) continue;
            total_water += max(cw_val[j], ccw_val[j]);
        }
        ans[l] = total_water;
    }

    for (int i = 0; i < n; ++i) {
        cout << ans[i] << (i == n - 1 ? "" : " ");
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}
