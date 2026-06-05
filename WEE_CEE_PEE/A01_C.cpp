#include<bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		long long n, m;
		cin >> n >> m;
		string s;
		cin >> s;
		vector<long long> p(m);
		for(int i = 0; i < m; i++){
			cin >> p[i];
		}

		map<char, long long> letters;

		for(char c = 'a'; c <= 'z'; c++){
			letters[c] = 0;
		}

		vector<long long> diff(n, 0);
		vector<long long> freq(n);

		for(long long x: p){
			diff[0]++;
			if(x < n) diff[x]--;
		}

		long long cur = 0;
		for(int i = 0; i < n; i++){
			cur += diff[i];
			long long times = cur + 1;
			freq[i] = times;
		}
		for(int i = 0; i < n; i++){
			letters[s[i]] += freq[i];
		}
		for(char c = 'a'; c <= 'z'; c++){
			cout << letters[c] << " ";
		}
		cout << "\n";
	}
}
