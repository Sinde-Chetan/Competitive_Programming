#include<bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<string> col(2);
		cin >> col[0];
		cin >> col[1];
		vector<int> dp(n+2, 0);
		for(int i = n-1 ; i >= 0 ; i--){
			dp[i] = (col[0][i] != col[1][i]) + dp[i+1];
			if(i < n-1){
				int cost = (col[0][i] != col[0][i+1]) + (col[1][i] != col[1][i+1]);
				dp[i] = min(dp[i], cost + dp[i+2]);
			}
		}
		cout << dp[0] << "\n";
	}
}
