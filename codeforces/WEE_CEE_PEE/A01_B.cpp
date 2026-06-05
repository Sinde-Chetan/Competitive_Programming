#include<bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		long long n, k;
		cin >> n >> k;
		long long time = 0;
		long long comp = 1;
		while(comp < n && comp < k){
			comp = 2*comp;
			time++;
		}
		if(comp < n){
			if((n-comp)%k == 0) time += (n-comp)/k;
			else time += (n-comp)/k + 1;
		}
		cout << time << "\n";
	}
}
