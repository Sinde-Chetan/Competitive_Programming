#include<bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		long long n, d;
		cin >> n >> d;
		vector<long long> a(n);
		for(auto &x : a) cin >> x;
		int left = n-d+1;
		int right = d+1;
		vector<long long> pref(n + 1, 0);
		for(int i = 0; i < n; i++){
			pref[i+1] = pref[i] + a[i];
		}

		long long mx = 0;
		for(int i = 0; i < n; i++){
			int left = (i-d+n)%n;
			int right = (i+d)%n;

			long long sum = 0;
			if(left <= right){
				sum = pref[right+1] - pref[left];
			}
			else{
				sum = pref[n]-pref[left] + pref[right+1]-pref[0];
			}
			long long s = sum - a[i];
			if((2*d*a[i] - s) > 0) mx += 2*d*a[i] - s;

		}

		cout << mx << "\n";
	}
}
