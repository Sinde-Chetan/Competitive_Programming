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
vector<char> stack;
for(char c : s){
if(!stack.empty() && stack.back() == c) stack.pop_back();
else stack.push_back(c);
}
if(stack.empty()) cout << "YES\n";
else cout << "NO\n";
}
}
