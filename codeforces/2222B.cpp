  #include <bits/stdc++.h>
  using namespace std;

  int main() {
      int t;
      cin >> t;

      while (t--) {
          int n, m;
          cin >> n >> m;

          vector<long long> a(n);
          for (auto &x : a) cin >> x;

          vector<int> ind(m);
          for (auto &x : ind) cin >> x;

          vector<pair<long long, int>> pos;
          for (int i = 0; i < n; i++) {
              if (a[i] >= 0) pos.push_back({a[i], i});
          }

          sort(pos.rbegin(), pos.rend());

          vector<int> mark(n, 0);
          int oper = 0;
		vector<int> used(m, 0);

          if (!pos.empty()) {

              for (int i = 0; i < m; i++) {
                  if (oper >= m) break;
		  if(used[i]) continue;

                  for (auto &p : pos) {
                      if (mark[p.second] != 0) continue;

                      if (((p.second - ind[i]) & 1)) {
                          mark[p.second]++;
                          oper++;
			used[i]++;
			break;
                      }
                  }
              }

              for (int i = 0; i < m; i++) {
                  if (oper >= m) break;
		  if(used[i]) continue;

                  for (auto &p : pos) {
                      if (((p.second - ind[i]) & 1)) {
                          oper++;
			used[i]++;
			break;
                      }
                  }
              }
          }

          long long oddNegMax = LLONG_MIN;
          long long evenNegMax = LLONG_MIN;

          for (int i = 0; i < n; i++) {
              if (a[i] < 0) {
                  if (i % 2 == 0)
                      evenNegMax = max(evenNegMax, a[i]);
                  else
                      oddNegMax = max(oddNegMax, a[i]);
              }
          }
	bool ok = false;
	bool found = false;
	  int oddNegMax_ind = -1;
	  int evenNegMax_ind = -1;
	  for(int i = 0; i < n; i++){
		  if(a[i] == evenNegMax && i%2 == 0){
			  ok = true;
			  evenNegMax_ind = i;
		  }
		  if(a[i] == oddNegMax && i%2 != 0){
			  found = true;
			  oddNegMax_ind = i;
		  }
		  if(ok && found) break;
	  }


          for (int i = 0; i < m; i++) {
              if (oper >= m) break;
		if(used[i]) continue;

              if (ind[i] & 1){
                  mark[evenNegMax_ind]++;
		used[i]++;
		}
              else{
                  mark[oddNegMax_ind]++;
		used[i]++;
		}
              oper++;
          }

          long long sum = 0;
          for (int i = 0; i < n; i++) {
              if (mark[i] != 0) continue;
              sum += a[i];
          }

          cout << sum << "\n";
      }

      return 0;
  }
