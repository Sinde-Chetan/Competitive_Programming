#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;

    while (tc--) {
        int n;
        long long T, a, b;
        cin >> n >> T >> a >> b;

        vector<int> type(n);
        vector<long long> deadline(n);

        int easyTotal = 0, hardTotal = 0;

        for (int i = 0; i < n; i++) {
            cin >> type[i];
            if (type[i] == 0) easyTotal++;
            else hardTotal++;
        }

        for (int i = 0; i < n; i++) {
            cin >> deadline[i];
        }

        vector<pair<long long, int>> v;

        for (int i = 0; i < n; i++) {
            v.push_back({deadline[i], type[i]});
        }

        sort(v.begin(), v.end());

        long long spent = 0;
        int easyDone = 0, hardDone = 0;
        int ans = 0;

        // Check time before first deadline
        long long curTime = v[0].first - 1;

        if (curTime >= 0 && spent <= curTime) {
            long long rem = curTime - spent;

            int easyLeft = easyTotal - easyDone;
            int hardLeft = hardTotal - hardDone;

            long long takeEasy = min((long long)easyLeft, rem / a);
            rem -= takeEasy * a;

            long long takeHard = min((long long)hardLeft, rem / b);

            ans = max(ans, (int)(takeEasy + takeHard));
        }

        for (int i = 0; i < n; i++) {

            if (v[i].second == 0) {
                spent += a;
                easyDone++;
            }
            else {
                spent += b;
                hardDone++;
            }

            long long nextTime;

            if (i == n - 1)
                nextTime = T;
            else
                nextTime = v[i + 1].first - 1;

            if (nextTime >= 0 && spent <= nextTime) {

                long long rem = nextTime - spent;

                int solved = easyDone + hardDone;

                int easyLeft = easyTotal - easyDone;
                int hardLeft = hardTotal - hardDone;

                long long takeEasy = min((long long)easyLeft, rem / a);
                rem -= takeEasy * a;

                long long takeHard = min((long long)hardLeft, rem / b);

                ans = max(ans,
                          solved + (int)takeEasy + (int)takeHard);
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
