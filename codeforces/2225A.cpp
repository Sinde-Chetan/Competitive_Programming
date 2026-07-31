#include<bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		long long x, y;
		cin >> x >> y;
		long long n = y/x;
		long long ans = x;
		bool found = false;
		for(int i = 2 ; i < n; i++){
			long long temp = x*i;
			if(y % temp != 0){
				found = true;
				break;
			}
		}
	if(found) cout << "YES" << "\n";
	else cout << "NO" << "\n";
	}
}
