#include<bits/stdc++.h>

using namespace std;

int main(){
int t;
cin >> t;
while(t--){
long long n;
cin >> n;
long long crim = 0;
for(long long i = 1; i <= n; i++){
crim += (n/i)*(n/i);
}
cout << crim << "\n";
}
}
