#include<bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<long long> b(n);
		for(int i = 0; i < n; i++){
			cin >> b[i];
		}
		sort(b.begin(), b.end());
		reverse(b.begin(), b.end());
		long long x = b[0];
		long long y = b[1];
		bool found = true;
		for(int i = 2; i < n; i++){
			if(b[i] != b[i-2]%b[i-1]) found = false;
		}
		if(found) cout << x << " " << y << "\n";
		else cout << "-1" << "\n"; 
	}
}
