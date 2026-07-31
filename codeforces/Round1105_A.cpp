#include<bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		long long n, k;
		cin >> n >> k;

		long long sum = 0;
		for(long long p = 1; p <= n; p *= 2){
			long long bits = min(k, n/p);
			sum += bits;
			n -= bits*p;
		}
		cout << sum <<"\n";
	}
}
