#include<bits/stdc++.h>

using namespace std;

int main(){
	int n, q;
	cin >> n >> q;
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	vector<int> diff(n, 0);
	vector<int> freq(n, 0);
	for(int i = 0; i < q; i++){
		int l, r;
		cin >> l >> r;
		l--;
		r--;
		diff[l]++;

		if(r+1 < n) diff[r+1]--;
	}
	freq[0] = diff[0];
	for(int i = 1; i < n; i++){
		freq[i] = freq[i-1] + diff[i];
	}
	sort(a.begin(), a.end());
	sort(freq.begin(), freq.end());

	long long sum = 0;

	for(int i = 0; i < n; i++){
		sum += 1LL*a[i]*freq[i];
	}
	cout << sum << "\n";
}

