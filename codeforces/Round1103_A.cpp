#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        
        int n;
        cin >> n;
        vector<int> ht(n);
        for(auto &x : ht) {cin >> x;}
        int mn = INT_MAX;
        int mx = 0;
        for(auto &x : ht){
            
                if(x <= mn) mn = x;
                if(x >= mx) mx = x;
        }
        cout << mx - mn + 1<< "\n";
    }

    return 0;
}
