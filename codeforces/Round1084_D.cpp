#include<bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){

		int n, x, y;
		cin >> n >> x >> y;

		vector<int> a(n);
		for(int &i : a) cin >> i;

		vector<int> lr;
		vector<int> mid;
		for(int i = 0; i < n; i++){
			if(i < x || i >= y) lr.push_back(a[i]);
			else mid.push_back(a[i]);
		}
		auto min_it = min_element(mid.begin(), mid.end());

		rotate(mid.begin(), min_it, mid.end());

		int ind = lr.size();

		for(int i = 0; i < lr.size(); i++){
			if(lr[i] > mid[0]){
				ind = i;
				break;
			}
		}
		vector<int> res(n);
		for(int i = 0; i < n; i++){
			if(i < ind) res[i] = lr[i];
			else if(i >= ind && i < mid.size() + ind) res[i] = mid[i-ind];
			else res[i] = lr[ind + i - (mid.size() + ind)];
		}
		for(int i : res){
			cout << i << " ";
		}
		cout << "\n";
	}
}
