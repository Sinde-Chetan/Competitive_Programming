#include<bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<long long> c(n);
		for(int i = 0; i < n; i++){
			cin >> c[i];
		}
		long long sum = 0;
		long long count = 0;
		long long pairs = 0;
		long long cnt1 = 0;
		bool allOnes = true;
		vector<long long> greater;
		for(long long i : c){
			if(i > 1){
				allOnes = false;
				count += i;
				pairs++;
				greater.push_back(i);
			}
			else if(i == 1) cnt1++;
			sum += i;
		}
		for(long long i : greater){
			if(pairs == 1){
				if(cnt1 >= i/2){
					count += i/2;
					cnt1 -= i/2;
				}
				else{
					count += cnt1;
					cnt1 = 0;
				}
			}
			else{
				if(cnt1 >= i/2 - 1){
					count += i/2 - 1;
					cnt1 -= i/2 - 1;
				}
				else{
					count += cnt1;
					cnt1 = 0;
				}
			}
		}
		if(allOnes || sum < 3) cout << "0" << "\n";
		else cout << count << "\n";
	}
}
