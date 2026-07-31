#include<bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<int> a(n);
		vector<int> cnt1(n + 1, 0), cnt2(n + 1, 0), cnt3(n + 1, 0);

		for (int i = 0; i < n; i++) {
			cin >> a[i];
			cnt1[i + 1] = cnt1[i] + (a[i] == 1 ? 1 : 0);
			cnt2[i + 1] = cnt2[i] + (a[i] == 2 ? 1 : 0);
			cnt3[i + 1] = cnt3[i] + (a[i] == 3 ? 1 : 0);
		}
		vector<int> f(n+1);
		for(int i = 0; i <=n; i++){
			f[i] = cnt1[i] + cnt2[i] - cnt3[i];
		}
		vector<int> suff(n+1, -2e9);
		suff[n-1] = f[n-1];
		for(int i = n-2; i >= 1; i--) suff[i] = max(f[i], suff[i+1]);
		bool ok = false;
		for(int i = 1; i <= n-2; i++){
			if(cnt1[i] >= cnt2[i] + cnt3[i]){
				if(suff[i+1] >= f[i]){
					ok = true;
					break;
				}
			}
		}
		if(ok) cout << "YES\n";
		else cout << "NO\n";
	}
}
