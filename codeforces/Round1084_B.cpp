#include<bits/stdc++.h>

using namespace std;

int main(){
int t;
cin >> t;
while(t--){
int n;
cin >> n;
vector<int> a(n);
for(int &i : a) cin >> i;
bool inc = true;
for(int i = 0; i < n-1; i++){
if(a[i] > a[i+1]){
inc = false;
break;
}
} 
if(inc) cout << n << "\n";
else cout << "1\n";
}
}
