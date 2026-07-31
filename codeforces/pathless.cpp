#include<bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n, s;
		cin >> n >> s;
		vector<int> a(n);
		for(int &x : a) cin >> x;
		int sum = 0;
		for(int i = 0; i < n; i++){
			sum += a[i];
		}
		if(s < sum || s == sum + 1){
			sort(a.begin(), a.end());
			for(int i = 0; i < n; i++){
				if(a[i] == 1) continue;
				cout << a[i] << " ";
			}
			for(int i = 0; i < n; i++){
				if(a[i] == 0 || a[i] == 2) continue;
				cout << a[i] << " ";
			}
			cout << "\n";
			continue;
		}
		cout << "-1\n";
	}
}
