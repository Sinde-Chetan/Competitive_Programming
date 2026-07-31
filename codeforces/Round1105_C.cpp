#include<bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<int> a(n);
		int sum = 0;
		int pos = 0;
		for(auto &x : a) cin >> x;
		for(int i = 0; i < n; i++){
			sum ^= a[i];
			if(a[i] > 0){
				pos++;
			}
		}
		if(pos <= 1){
			cout << "0\n";
			continue;
		}
		if(sum == 0){
			cout << "1\n";
			continue;
		}
		long long win = 0;
		for(int i = 0; i < n; i++){
			if((a[i]^sum) < a[i]) win++;
		}
		cout << win%998244353 << "\n";
	}
}
