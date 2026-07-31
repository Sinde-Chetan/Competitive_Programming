#include<bits/stdc++.h>

using namespace std;

int main(){
int t;
cin >> t;
while(t--){
int n;
cin >> n;
string s;
cin >> s;

int alt = 0;
for(int i = 0; i < n-1; i++){
if(s[i] != s[i+1]) alt++;
}
if(alt == 1) cout << "2\n";
else cout << "1\n";
}
}
