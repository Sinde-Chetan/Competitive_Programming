#include<bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<long long> a(n);
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		long long k = 0;
		long long max_so_far = a[0];
		for(int i = 1; i < n; i++){
			if(a[i] < max_so_far){
				k = max(k, max_so_far - a[i]);
			}
			max_so_far = max(a[i], max_so_far);
		}
		max_so_far = a[0];
		for(int i = 1; i < n; i++){
			if(a[i] < max_so_far){
				a[i] += k;
			}
			max_so_far = max(a[i], max_so_far);
		}
		bool sorted = true;
		for(int i = 1; i < n; i++){
			if(a[i] < a[i-1]){
				sorted = false;
				break;
			}
		}
		if(sorted) cout << "YES" << "\n";
		else cout << "NO" << "\n";
	}
}
