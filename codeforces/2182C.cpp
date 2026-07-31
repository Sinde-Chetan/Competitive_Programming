#include<bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<int> a(n);
		vector<int> b(n);
		vector<int> c(n);
		for(auto &x : a) cin >> x;
		for(auto &x : b) cin >> x;
		for(auto &x : c) cin >> x;

		long long countAB = 0;
		long long countBC = 0;

		for(int i = 0 ; i < n ; i++){
			int j = 0;
			while(j < n){
				if(a[(i+j)%n] >= b[j]) break;
				j++;
			}
			if(j == n) countAB++;
		}
		for(int i = 0 ; i < n ; i++){
			int j = 0;
			while(j < n){
				if(c[(i+j)%n] <= b[j]) break;
				j++;
			}
			if(j == n) countBC++;
		}
		cout << countAB*countBC*n << "\n";
	}
}
