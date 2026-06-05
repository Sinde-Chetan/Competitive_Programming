#include<iostream>
#include<vector>

using namespace std;

int main(){
	int test;
	cin >> test;
	while(test--){
		int n;
		cin >> n;
		vector<int> w(n);
		for(int i = 0; i < n; i++){
			cin >> w[i];
		}
		int count_0 = 0;
		int count_1 = 0;
		int count_2 = 0;
		for(int i: w){
			if(i == 0) count_0++;
			else if(i == 1) count_1++;
			else count_2++;
		}
		int pairs_1_2 = min(count_1, count_2);
		count_1 -= pairs_1_2;
		count_2 -= pairs_1_2;
		cout << count_0 + pairs_1_2 + count_1/3 + count_2/3 << endl;
	}
}
