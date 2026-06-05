#include<bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		int count = 0;

                int j = 0;
		while(j < s.size()){
			if(s[j] == '4'){
				s.erase(j, 1);
				count++;
			}
			else j++;
		}
		int p = s.size();
		while(p--){
			if(s[p] == '2') break;
		}
		if(p > 0){
			for(int q = 0; q < p; q++){
				if(s[q] == '1' || s[q] == '3') count++;
			}
		}
		cout << count << "\n";
	}
}
