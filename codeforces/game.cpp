#include<bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n, m;
		cin >> n >> m;
		vector<int> a(n);
		vector<int> b(m);
		for(int &x : a) cin >> x;
		for(int &x : b) cin >> x;

		vector<bool> alic(101, false);
		vector<bool> bob(101, false);
		for(int x : a) alic[x] = true;
		for(int x : b) bob[x] = true;

		int com = 0;
		for(int i = 0; i < 101; i++){
			if(alic[i] && bob[i]) com++;
		}
		if(n <= m) cout << 2*(n - com) + 1 << "\n";
		else cout << 2*(m - com) + 2 << "\n";
	}
}
