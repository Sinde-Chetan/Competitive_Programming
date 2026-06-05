#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int n, x, s;
        cin >> n >> x >> s;

        string u;
        cin >> u;

        vector<int> cnt(s + 1, 0);
        cnt[0] = x;

        int seated = 0;

        for(char c : u){

            if(c == 'I'){
                if(cnt[0] > 0){
                    cnt[0]--;
                    cnt[1]++;
                    seated++;
                }
            }

            else if(c == 'E'){
                bool done = false;

                for(int k = 1; k < s; k++){
                    if(cnt[k] > 0){
                        cnt[k]--;
                        cnt[k+1]++;
                        seated++;
                        done = true;
                        break;
                    }
                }

                if(!done){
     
                    if(cnt[0] > 0){
                        cnt[0]--;
                        cnt[1]++;
                        seated++;
                    }
                }
            }

            else { 
                bool done = false;

                    for(int k = 1; k < s; k++){
                    if(cnt[k] > 0){
                        cnt[k]--;
                        cnt[k+1]++;
                        seated++;
                        done = true;
                        break;
                    }
                }

                if(!done && cnt[0] > 0){
                    cnt[0]--;
                    cnt[1]++;
                    seated++;
                }
            }
        }

        cout << seated << "\n";
    }
}
