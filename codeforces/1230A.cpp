#include<bits/stdc++.h>

using namespace std;

int main(){
	vector<int> a(4);
	for(int i = 0; i < 4; i++){
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	int sum1 = 0, sum2 = a[3];
	for(int i = 0; i < 3; i++){
		sum1 += a[i];
	}
	if(sum1 < sum2) cout << "NO" << "\n";
	else if(sum1 == sum2) cout << "YES" << "\n";
	else{
		sum1 -= a[0];
		sum2 += a[0];
		if(sum1 == sum2) cout << "YES" << "\n";
		else cout << "NO" << "\n";
	}
}
