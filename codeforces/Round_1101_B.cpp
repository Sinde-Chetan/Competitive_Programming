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
		vector<long long> a(n);
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		long long mn = a[0];
		long long sum = 0;
		for(int i = 0; i < n; i++){
			sum += a[i];
			long long avg = sum/(i+1);
			mn = min(mn, avg);
			cout << mn << " ";
		}
		cout << endl;
	}
}
