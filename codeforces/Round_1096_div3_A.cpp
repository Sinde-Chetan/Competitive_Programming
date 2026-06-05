#include<iostream>

using namespace std;

int main(){
	int testcases;
	cin >> testcases;
	while(testcases--){
		int x,y;
		cin >> x >> y;
	        if((x%2==0 && y%2==0) || (x%2==0 && y%2!=0) || (x%2!=0 && y%2==0)) cout << "YES" << endl;
        	else cout << "NO" << endl;
	}
}
