#include<bits/stdc++.h>

using namespace std;

int main(){
        int t;
        cin >> t;
        while(t--){
                int n;
                cin >> n;
                vector<long long> a(n);
                for(int i = 0; i < n; i++){
                        cin >> a[i];
                }
                vector<tuple<int, int, int>> lrd;

                for(int i = 0; i < n; i++){
                        int pos = i;
                        for(int j = i; j < n; j++){
                                if(a[j] < a[pos]) pos = j;
                        }
                        if(pos != i){
                                int l = i;
                                int r = pos;
                                int d = pos - i;

                                vector<long long> tmp;

                                for(int j = l + d; j <= r; j++) {tmp.push_back(a[j]);}
                                for(int j = l; j < l+d; j++) {tmp.push_back(a[j]);}
                                for(int j = l; j <= r; j++){
                                        a[j] = tmp[j-l];
                                }
                                lrd.push_back({l+1, r+1, d});
                        }
                }
                cout << lrd.size() << "\n";
                for(auto &x : lrd){
                        cout << get<0>(x) << " " << get<1>(x) << " " << get<2>(x) << "\n";
                }
        }
}
