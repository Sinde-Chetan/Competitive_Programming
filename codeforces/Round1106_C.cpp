#include<bits/stdc++.h>

using namespace std;

int main(){
int t;
cin >> t;
while(t--){
long long n;
cin >> n;
vector<long long> p(n+1);
for(int i = 2; i <= n; i++) cin >> p[i];

vector<long long> dep(n+1, 0);
vector<long long> maxdep(n+1, 0);
for(int i = 2; i <= n; i++){
dep[i] = dep[p[i]] + 1;
maxdep[i] = dep[i];
}
vector<long long> max1(n + 1, -1);
vector<long long> max2(n + 1, -1);

for(int i = n; i >= 2; i--){
long long par = p[i];
long long mx = maxdep[i];

if(mx > max1[par]){
max2[par] = max1[par];
max1[par] = mx;
}
maxdep[par] = max(maxdep[par], mx);
}
long long ans = n;
for(int i = 1; i <= n; i++){
if(max2[i] != -1){
ans += max(0LL, max2[i] - dep[i]);
}
}
cout << ans << "\n";
}
}
