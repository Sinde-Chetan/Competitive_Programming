#include<bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){\
		int n;
		cin >> n;
		vector<int> h(n);
		for(auto &x : h) cin >> x;
		int sum = h[0];
		for(int i = 1 ; i < n ; i++){
			if(h[i] > h[i-1]) {
				sum += h[i-1];
				h[i] = h[i-1];
			}
			else sum += h[i];
		}
		cout << sum << "\n";
	}
}
