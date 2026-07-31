#include<bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		long long n;
		int k;
		cin >> n >> k;
		vector<long long> a(k);
		for(int i = 0; i < k; i++){
			cin >> a[i];
		}
		sort(a.begin(), a.end());
		long long ans = 0;
		for(int i = 0; i < k-1; i++){
			ans += 2*a[i] - 1;
		}
		cout << ans << "\n";
	}
}
