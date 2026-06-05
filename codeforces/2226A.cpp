#include<bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<int> a(n);
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		long long cost = 0;
		for(int i = 0; i < n; i++){
			if(a[i] != 1) cost += a[i];
		}
		if(a[n-1] == 1) cost += 1;
		cout << cost << "\n";

	}
}

