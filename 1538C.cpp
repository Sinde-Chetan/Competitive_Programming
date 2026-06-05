#include<bits/stdc++.h>

using namespace std;

int ge(vector<int>& a, int start, int left_val){
	int left = start;
	int right = a.size();
	while(left < right){
		int mid = left + (right-left)/2;
		if(a[mid] >= left_val){
			right = mid;
		}
		else{
			left = mid+1;
		}
	}
	return left;
}

int gt(vector<int>& a, int start, int right_val){
	int left = start;
	int right = a.size();
	while(left < right){
		int mid = left + (right-left)/2;
		if(a[mid] > right_val){
			right = mid;
		}
		else{
			left = mid+1;
		}
	}
	return left;
}

int main(){
	int test;
	cin >> test;
	while(test--){
		int n, l, r;
		cin >> n >> l >> r;
		vector<int> a(n);
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		sort(a.begin(), a.end());
		long long result = 0;
		for(int i = 0; i < n-1; i++){
			int left = l-a[i];
			int right = r-a[i];
			int first_l = ge(a, i+1, left);
			int first_r = gt(a, i+1, right);
			result += first_r - first_l;
		}
		cout << result << "\n";
	}
}
