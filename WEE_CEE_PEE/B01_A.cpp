#include<bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n, k;
		cin >> n >> k;
		vector<int> a(n);
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		int i = 0;
		int oper = 0;
		while(oper < k){
			bool all_zer = true;
			for(int i = 0; i < n-1; i++){
				if(a[i] != 0) {
					all_zer = false;
					break;
				}
			}
			if(all_zer) break;
			if(a[i] > 0){
				a[i]--;
				a[n-1]++;
				oper++;
			}
			else {
				i++;
			}
		}
		for(int j = 0; j < n; j++){
			cout << a[j] << " ";
		}
		cout << "\n";
	}
}

