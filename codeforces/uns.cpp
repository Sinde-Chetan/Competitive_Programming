#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n, k;
    if (!(cin >> n >> k)) return;
    
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    if (n == 0) {
        cout << 0 << "\n";
        return;
    }

    vector<int> sizes;
    int current_size = 1;
    for (int i = 1; i < n; ++i) {
        if (a[i] == a[i - 1]) {
            current_size++;
        } else {
            sizes.push_back(current_size);
            current_size = 1;
        }
    }
    sizes.push_back(current_size);

    sort(sizes.begin(), sizes.end());

    int m_total = sizes.size();
    vector<long long> suff(m_total + 1, 0);
    for (int i = m_total - 1; i >= 0; --i) {
        suff[i] = suff[i + 1] + sizes[i];
    }

    vector<int> u = sizes;
    u.erase(unique(u.begin(), u.end()), u.end());

    int ans = 0;
    for (int val : u) {
        int idx = lower_bound(sizes.begin(), sizes.end(), val) - sizes.begin();
        long long M = m_total - idx;
        long long S = suff[idx];
        long long L = val - 1;

        if ((k - S) % M == 0) {
            long long x_final = (k - S) / M;
            if (x_final >= -L) {
                ans++;
            }
        }
    }

    cout << ans << "\n";
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
