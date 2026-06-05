#include<bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		vector<long long> b(7);
		long long a, c, d;
		for(int i = 0; i < 7; i++){
			cin >> b[i];
		}
		a = b[6] - b[5];
		c = b[6] - b[4];
		d = b[6] - (a+c);
		cout << a << " " << c << " " << d << "\n";
	}
}
