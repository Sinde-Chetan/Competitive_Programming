#include <bits/stdc++.h>
using namespace std;

void solve(const vector<int>& arr, int n){

	for(int i = 0; i < n; i++){
		vector<long long> values(n, LLONG_MAX);
		values[i] = 0;

		int idx = (i + 1) % n;
		while(idx != i){
			int prev = (idx - 1 + n) % n;
			values[idx] = min(values[idx], max(values[prev], (long long)arr[prev]));
			idx = (idx + 1) % n;
		}

		idx = (i - 1 + n) % n;
		while(idx != i){
			int prev = (idx + 1) % n;
			values[idx] = min(values[idx], max(values[prev], (long long)arr[idx]));
			idx = (idx - 1 + n) % n;  
		}

		long long total_sum = 0;
		for(int j = 0; j < n; j++) {
			total_sum += values[j];
		}
		cout << total_sum << " ";
	}

	cout << "\n";
}

int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<int> arr(n);
		for(int i = 0; i < n; i++){
			cin >> arr[i];
		}

		solve(arr, n);
	}

	return 0;
}

