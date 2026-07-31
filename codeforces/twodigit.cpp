#include<bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int main(){
int t;
cin >> t;
while(t--){
string a, b;
cin >> a >> b;
int n = a.size();
int m = b.size();

vector<int> prefa(n+1, 0), prefb(m+1, 0);
for(int i = 0; i < n; i++) prefa[i+1] = (prefa[i] + (a[i] - '0'))%10;
for(int i = 0; i < m; i++) prefb[i+1] = (prefb[i] + (b[i] - '0'))%10;

if(prefa[n] != prefb[n]){
cout << "-1\n";
continue;
}

vector<vector<int>> dp(n+1, vector<int>(m+1, -INF));
dp[0][0] = 0;
for(int i = 0; i <= n; i++){
for(int j = 0; j <= m; j++){
if(dp[i][j] < 0) continue;
for(int k = i+1; k <= n; k++){
int suma = (prefa[k] - prefa[i] + 10)%10;
for(int p = j+1; p <= m; p++){
int sumb = (prefb[p] - prefb[j] + 10)%10;
if(suma == sumb) dp[k][p] = max(dp[k][p], dp[i][j] + 1);
}
}
}
}
cout << dp[n][m] << "\n";
}
}
