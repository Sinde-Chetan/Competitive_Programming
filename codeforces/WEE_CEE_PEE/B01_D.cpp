#include<bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int m = 2*n;
		vector<long long> miners(n);
		vector<long long> mines(n);
		int i = 0;
		int j =0;
		while(m--){
			int x, y;
			cin >> x >> y;
			if(x == 0){
				miners[i] =  abs(y);
				i++;
			}
			else{
				mines[j] = abs(x);
				j++;
			}
		}
		sort(miners.begin(), miners.end());
		sort(mines.begin(), mines.end());

		long double sum = 0;
		for(int i = 0; i < n; i++){
			sum += (long double)sqrt(miners[i]*miners[i] + mines[i]*mines[i]);
		}
		printf("%.15Lf\n", sum);
	}
}
