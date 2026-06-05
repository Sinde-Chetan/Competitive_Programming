#include<bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		long long x, y, k;
		cin >> x >> y >> k;
		long long rem = (k*(y+1)-1)%(x-1);
		long long s_trad = rem != 0 ? (k*(y+1)-1)/(x-1) + 1 : (k*(y+1)-1)/(x-1);
		cout << s_trad + k << "\n";
	}
}

