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
		vector<long long> b(n);
		for(int i = 0; i < n; i++){
			cin >> b[i];
		}
		vector<pair<long long, long long>> v;
		for(int i = 0; i < n; i++){
			v.push_back({a[i], b[i]});
		}
		sort(v.begin(), v.end());

		long long sum = 0;
		for(int i = 0; i < n; i++){
			sum += v[i].second;
		}
		long long time = sum;
		for(int i = 0; i < n; i++){
			sum -= v[i].second;
			time = min(time, max(v[i].first, sum));
		}
		cout << time << "\n";
	}
}
