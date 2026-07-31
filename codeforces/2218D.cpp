#include<bits/stdc++.h>

using namespace std;

int main(){
int t;
cin >> t;
while(t--){
int n;
cin >> n;
long long i = 0;
while(i < n){
if(pow(2, i) < 1e18/2) cout << pow(2, i) << " ";
else if(pow(2, i) >= 1e18/2)
i++;
}
}
}
