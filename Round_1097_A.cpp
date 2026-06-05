#include<iostream>
#include<vector>

using namespace std;

int main(){
	int test;
	cin >> test;
	while(test--){
		int n;
		long long int pos_count = 0;
		cin >> n;
		vector<long long int> arr(n);
		for(int i = 0; i < n; i++){
			cin >> arr[i];
		}
		for(int j = n-2; j >= 0; j--){
			if(arr[j] <= 0) arr[j] += arr[j+1];
			else{
				if(arr[j+1] > 0) arr[j] += arr[j+1];
			}
		}
		for(long long int i: arr){
			if(i > 0) pos_count++;
		}
		cout << pos_count << endl;
	}
}
