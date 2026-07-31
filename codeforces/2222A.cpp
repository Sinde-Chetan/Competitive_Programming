#include<bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<int> a(n);
		bool yes = true;
		for(auto &x: a) cin >> x;
		int MAX = 100*n;
		vector<int> dp(MAX + 1, 0);
		dp[0] = 1;
		for(int i = 0; i < n; i++){
			vector<int> ndp(MAX + 1, 0);
			for(int score = 0; score <= MAX; score++){
				if(!dp[score]) continue;
				for(int x = 0; x <= a[i]; x++){
					int add = x*(100/a[i]);
					if(score + add <= MAX){
						ndp[score + add] = 1;
					}
				}
			}
			dp = ndp;
		}
		for(auto &x : dp){
			if(x == 0){
				yes = false;
				break;
			}
		}
		if(yes) cout << "YES\n";
		else cout << "NO\n";
	}
}
