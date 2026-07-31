#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  vector<int> coins(n);
  for (auto &x : coins)
    cin >> x;
  sort(coins.begin(), coins.end());
  long long sum = 1;
  for (auto &x : coins) {
    if (x > sum)
      break;
    sum += x;
  }
  cout << sum << "\n";
  return 0;
}
