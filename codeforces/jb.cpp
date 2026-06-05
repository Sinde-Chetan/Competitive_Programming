#include<bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n, m, k;
		cin >> n >> m >> k;
		if(k > 3) cout << "0" << "\n";
		if(k == 1) cout << "1" << "\n";
		if(k == 2){
			if(m < n) cout << m << "\n";
			else cout << (n-1) + (m/n);
		}
		if(k == 3){
			if(m < n) cout << "0" << "\n";
			else cout << m - n + 1 - (m/n) << "\n";
		}
	}
}
