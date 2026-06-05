#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
	int test;
	cin >> test;
	while(test--){
		int n;
		cin >> n;
		vector<long long int> a(n);
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		sort(a.begin(), a.end());

		int result = n;
		
		for(int i = 0; i < n;){
			int j = i;
			while(j < n && a[i] == a[j]) j++;
			int left = i;
			int right = n-j;
			result = min(result, max(left, right));
			i = j;
		}

		cout << result << endl;
	}
}
