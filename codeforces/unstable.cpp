#include<bits/stdc++.h>

using namespace std;

int main(){
int t;
cin >> t;
while(t--){
long long n, k;
cin >> n >> k;
vector<int> a(n);
for(auto &x : a) cin >> x;
vector<long long> runs;
for (int i = 0; i < n; i++) {
    int j = i;
    while (j < n && a[j] == a[i]) j++;
    runs.push_back(j - i);
    i = j - 1;
}

}
}
