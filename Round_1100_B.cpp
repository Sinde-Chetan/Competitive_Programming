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
		vector<int> a(n);
		vector<int> b(n);
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		for(int i = 0; i < n; i++){
			cin >> b[i];
		}
		long long int sum = 0;
		long long int minimum = 0;
		for(int i = 0; i < n; i++){
			sum += a[i] > b[i] ? a[i]:b[i];
			long long int extra = a[i] < b[i] ? a[i]:b[i];
			minimum = minimum > extra ? minimum:extra;
		}
		cout << sum + minimum << endl;
	}
}
