#include<bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin >> t; 
       while(t--){
                string s;
                cin >> s;
                int ans = 0;
                for(int i = 0; i < s.size(); i++){
                        if(s[i] == '4') ans++;
                }
		
                vector<pair<int, int>> twos;
                for(int i = 0; i < s.size(); i++){
                        int len = 1;
                        int j = i;
                        if(s[i] == '2'){
                                j = i+1;
                                while(j < s.size() && len <= s.size()){
                                        if(s[j] == '2'){
                                                j++;
                                                len++;
                                        }
                                        else if(s[j] == '4') j++;
                                        else break;
                                }
                                twos.push_back({i, len});
                        }
                        i = max(i, j-1);
                }

                sort(twos.rbegin(), twos.rend());
		bool used = false;
		if(!twos.empty()){
			int cntEven = 0;
			int cntOdd = 0;
			for(int i = 0; i < twos[0].first; i++){
				if(s[i] == '1' || s[i] == '3') cntOdd++;
			}	
			for(int i = 0; i < s.size(); i++){	
				if(s[i] == '2') cntEven++;
			}
			if(cntOdd <= cntEven) {
				ans += cntOdd;
				used = true;
			}
		}
		if(!twos.empty() && !used){
                for(auto &p : twos){
                        bool ok = false;
                        int oddcnt = 0;
                        int evncnt = p.second;
                        for(int i = 0; i < p.first; i++){
                                if(s[i] == '1' || s[i] == '3') oddcnt++;
                        }
                        if(oddcnt <= evncnt){
                                ans += oddcnt;
                                ok = true;
                                break;
                        }
                        else ans += evncnt;
                        if(ok) break;
                }
		}
                cout << ans << "\n";
        }
}
