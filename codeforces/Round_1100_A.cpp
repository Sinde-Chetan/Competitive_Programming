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
		vector<int> seq(n);
		for(int i = 0; i < n; i++){
			cin >> seq[i];
		}
		int mx = *max_element(seq.begin(), seq.end());
		int mn = *min_element(seq.begin(), seq.end());
		if((mx - mn)%2 == 0) cout << (mx - mn)/2 << endl;
		else cout << (mx - mn)/2 + 1 << endl;
	}
}
