#include<bits/stdc++.h>

using namespace std;

int main(){
int t;
cin >> t;
while(t--){
int a, b, c, d;
cin >> a >> b >> c >> d;
string s;
cin >> s;
int n = s.size();
int countA = 0, countB = 0;
for(int i = 0; i < s.size(); i++){
if(s[i] == 'A') countA++;
else countB++;
}
if((countA != a+c+d)  || (countB != b+c+d)) cout << "NO" << "\n";
vector<pair<char, int>> alt_seg;
for(int i = 0; i < n; i++){
int j = i;
while(j + 1 < n && s[j] != s[j+1]){
j++;
}
if(j > i){
alt_seg.push_back({s[i], j-i+1});
}

i = max(j, i+1);

}

int ab_cnt = c, bc_cnt = d;

for(auto &p: alt_seg){
if(ab_cnt > 0 && p.first == 'A') {
ab_cnt -= p.second/2;
countA -= p.second/2;
countB -= p.second/2;
}
else if(ba_cnt > 0 && p.first == 'B') {
ba_cnt -= p.second/2;
countA -= p.second/2;
countB -= p.second/2;
}
}
}
}
