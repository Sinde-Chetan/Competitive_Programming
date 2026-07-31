#include<bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<int> p(n);
		for(int &x : p) cin >> x;

		vector<bool> used(n+1, false);
		int zeros = 0;
		int pos = -1;
		for(int i = 0; i < n; i++){
			if(p[i] == 0){
				used[0] = true;
				zeros++;
				pos = i;
			}
			else used[p[i]] = true;
		}
		if(zeros == 1){
			for(int i = 1; i <= n; i++){
				if(!used[i]){
					p[pos] = i;
					break;
				}
			}
		} 
		int first = -1;
		int last = -1;
		for(int i = 0; i < n; i++){
			if(p[i] != i+1) {
				first = i;
				break;
			}
		}
		for(int i = n-1; i >= 0; i--){
			if(p[i] != i+1){
				last = i;
				break;
			}
		}
		if(first == -1 || first == last) cout << "0\n"; 
		else cout << last - first + 1 << "\n";
	}
}
