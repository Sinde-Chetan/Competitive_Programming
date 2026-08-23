#include <bits/stdc++.h>

using namespace std;

int main() {

  int t;
  cin >> t;
  while (t--) {
    double N;
    cin >> N;

    int a, b;
    cin >> a >> b;

    vector<int> tel(a);
    for (auto &x : tel)
      cin >> x;

    vector<int> tim(b);

    for (auto &x : tim)
      cin >> x;

    vector<bool> tele(N, false);

    for (int x : tel)
      tele[x] = true;

    vector<bool> time(N, false);

    for (int x : tim)
      time[x] = true;
    vector<double> A(N);
    vector<double> B(N);
    B[N - 1] = 1.0;

    for (int i = N - 2; i >= 1; i--) {
      if (!tele[i + 1] && !time[i + 1]) {
        A[i] = A[i + 1];
        B[i] = B[i + 1];
      } else if (time[i + 1]) {
        A[i] = (1 + A[i + 1] * (N - i - 1)) / (N - i);
        B[i] = (N - i - 1) * B[i + 1] / (N - i);
      } else if (tele[i + 1]) {
        A[i] = (A[i + 1] * (N - i - 1)) / (N - i);
        B[i] = (B[i + 1] * (N - i - 1)) / (N - i);
      }
    }
    double ans = A[1] / (1 - B[1]);

    printf("%.6f\n", ans);
  }
}
