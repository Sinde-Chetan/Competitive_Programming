#include<bits/stdc++.h>

using namespace std;

int main(){
	string s;
	cin >> s;
	vector<int> ps(s.size(), 0);
	
	for(int i = 1; i < s.size(); i++){
		ps[i] = ps[i-1];
		if(s[i] == s[i-1]) ps[i]++;
	}
	int m;
	cin >> m;
	while(m--){
		int l,r;
		cin >> l >> r;
		cout << ps[r-1]-ps[l-1] << "\n";
	}
}
