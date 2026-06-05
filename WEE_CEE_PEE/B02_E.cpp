#include<bits/stdc++.h>

using namespace std;

int main(){
	int n;
	long long m;
	cin >> n >> m;
	vector<long long> a(n);
	vector<long long> b(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	for(int i = 0; i < n; i++){
		cin >> b[i];
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	long long result = m;
	for(int i = 0; i < n; i++){
		long long x = (b[i]-a[0]+m)%m;
		vector<long long> c(n);
		for(int j = 0; j < n; j++){
			c[j] = (a[j]+x)%m;
		}
		sort(c.begin(), c.end());
		bool found = true;
		for(int j = 0; j < n; j++){
			if(c[j] != b[j]) found = false;
		}
		if(found) result = min(result, x);
	}
	cout << result << "\n";
}
