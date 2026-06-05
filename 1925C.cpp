#include<bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n, k, m;
		cin >> n >> k >> m;
		string s;
		cin >> s;
		int boxes = 0;
		set<char> st;
		string miss;
		for(char c: s){
			st.insert(c);
			if((int)st.size() == k){
				boxes++;
				miss += c;
				st.clear();
			}
		}
		if(boxes >= n) cout << "YES" << "\n";
		else {
			string letters;
			for(int i = 0; i < k; i++){
				letters += char('a' + i);
			}
			string missing;
			
			for(char c: letters){
				if(st.find(c) == st.end()){
					missing += c;
					break;
				}
			}
			string ans = miss;
			ans += missing;

			while((int)ans.size() < n){
				ans += 'a';
			}
			cout << "NO" << "\n";
			cout << ans << "\n";
		}
	}
}

