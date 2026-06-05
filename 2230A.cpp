#include<bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		long long n, a, b;
		cin >> n >> a >> b;
		long long cost = 0;
		if(b <= a){
			if(n%3 != 0) cost += (n/3)*b + b;
			else cost += (n/3)*b;
		}
		else if(b <= 2*a){
			if(n%3 == 2) {
				if(n%3 != 0) cost += (n/3)*b + b;
				else cost += (n/3)*b;
			}
			else cost += (n/3)*b + (n%3)*a;
		}
		else if(b < 3*a){
			cost += (n/3)*b + (n%3)*a;	
		}
		else{
			cost += n*a;
		}
		cout << cost << "\n";
	}
}
