#include<bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<long long> a(n);
		vector<long long> b(n);
		for(auto &x : a) cin >> x;
		for(auto &x : b) cin >> x;
		vector<long long> diff(n);
		for(int i = 0; i < n; i++) diff[i] = a[i] - b[i];

		for(int i = n-1; i > 0; i--){
			if(diff[i] <= 0) continue;
			diff[i-1] += diff[i];
		}
		if(diff[0] > 0) cout << "NO\n";
		else cout << "YES\n";
	}
}
