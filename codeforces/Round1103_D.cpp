#include <bits/stdc++.h>
using namespace std;

int main() {

	int T;
	cin >> T;

	while (T--) {

		int n, k;
		cin >> n >> k;
		vector<int> a(n);
		for (int &x : a)
			cin >> x;

		sort(a.begin(), a.end());
		vector<vector<int>> segs;
		vector<int> cur;
		cur.push_back(a[0]);
		for (int i = 1; i < n; i++) {
			if (a[i] - a[i - 1] <= k)
				cur.push_back(a[i]);
			else {
				segs.push_back(cur);
				cur.clear();
				cur.push_back(a[i]);
			}
		}
		segs.push_back(cur);
		bool ok = false;
		for (auto &v : segs) {
			map<int, int> freq;
			for(int i = 0; i < v.size(); i++){
				freq[v[i]]++;
			}
			if(freq[v[v.size()-1]]%2 == 0){
				ok = true;
				break;
			}
			else{
				for(int j = v[v.size()-1]-1; j >= v[v.size()-1]-k; j--){
					if(freq[j] > 0){
						ok = true;
						break;
					}
				}
				if(ok) break; 
			}		
		}
		if(ok) cout << "YES\n";
		else cout << "NO\n";		
	}

	return 0;
}
