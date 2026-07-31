#include<bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int k;
		cin >> k;
		vector<int> c(k);
		for(auto &x : c) cin >> x;
		int cnt2 = 0;
		int cnt3 = 0;
		for(int x : c){
			if(x >= 3) cnt3++;
			if(x >= 2) cnt2++;
		}
		if(cnt3 >= 1 || cnt2 >= 2) cout << "YES\n";
		else cout << "NO\n";
	}
}
