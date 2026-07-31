#include<bits/stdc++.h>

using namespace std;
const long long MOD = 998244353;

long long mod(long long a, long long num){
	long long r = 1;
	while(num > 0){
		if(num & 1) r = r*a%MOD;
		a= a*a%MOD;
		num >>= 1;

	}
	return r;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		long long n, m, r, c;
		cin >> n >> m >> r >> c;
		long long dim = (r-1)*m + (c-1)*n - (r-1)*(c-1);
		cout << mod(2, dim) << "\n";
	}
}
