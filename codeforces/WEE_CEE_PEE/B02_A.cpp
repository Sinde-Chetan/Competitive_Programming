#include<bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int l, p, c, d, k;
		cin >> l >> p >> c >> d >> k;
		int pen, penc;
		if(l%c != 0) pen = l/c +1;
		else pen = l/c;
		if(p%d != 0) penc = p/d + 1;
		else penc = p/d;
		if(pen + penc > k) cout << "-1" << "\n";
		else cout << pen << " " << penc << "\n";
	}
}
