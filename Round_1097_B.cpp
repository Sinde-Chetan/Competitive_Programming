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
		vector<long long int> arr(n);
		for(int i = 0; i < n; i++){
			cin >> arr[i];
		}
		long long int mx = 0;
		int max_index = 0;
		for(int i = 0; i < n; i++){
			if(arr[i] > mx) {
				mx = arr[i];
				max_index = i;
			}
		}
		vector<long long int> result;
		vector<long long int> duplicates;
		vector<long long int> fin_result;
		fin_result.push_back(mx);
		result.push_back(mx);
		for(int i = 1; i < n; i++){
			if(arr[i] == mx && i == max_index) continue;
			result.push_back(arr[i]);

		}
		sort(result.begin() + 1, result.end());
		for(int i = 1; i < n; i++){
			fin_result.push_back(result[i]);
			int j = i+1;
        		while(j < n){
				if(result[j] == result[i]) duplicates.push_back(result[j]);
				j++;
			}
    		}
		for(int x: duplicates){
			fin_result.push_back(x);
		}
		long long int mex = 0;
		long long int sum = 0;
		vector<int> freq(n+2, 0);
		for(int i = 0; i < n; i++){
			if(fin_result[i] <= n && fin_result[i] >= 0){
				freq[fin_result[i]]++;
			}

			while(freq[mex] == 1){
				mex++;
			}
			sum += mx + mex;

		}
		cout << sum << endl;
	}
}
