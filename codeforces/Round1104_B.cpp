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
		for(auto &x : a) cin >> x;
		for(auto &x : b) cin >> x;
		int mxa = 0;
		if(mxa > b[n-1]){
			cout << "-1\n";
			continue;
		}
		int ans = 0;
		for(int i = 0 ; i < n ; i++){
			bool found = false;
			if(a[i] <= b[i]) continue;
			for(int j = i+1 ; j < n ; j++){
				if(a[j] <= b[i]){
					int temp = a[j];

					for (int k = j; k > i; k--) {
						a[k] = a[k - 1];
					}

					a[i] = temp;
					ans += j-i;
					found = true;
					break;
				}
			}
			if(!found && a[i]>b[i]){
				ans = -1;
				break;
			}
		}
		cout << ans << "\n";
	}
}
