#include<iostream>
#include<cmath>

using namespace std;

int main(){
	int test;
	cin >> test;
	while(test--){
		long long int n, x1, x2, k;
		cin >> n >> x1 >> x2 >> k;
		long long int diff_1 = abs(x1 - x2);
		long long int diff_2 = n - diff_1;
		if(n < 4) cout << "1" << endl;
		else if(diff_1 > diff_2) cout << diff_2 + k << endl;
		else cout << diff_1 + k << endl;
		
	}
}
