#include<bits/stdc++.h>

using namespace std;

int main(){
	int n, m;
	cin >> n >> m;
	vector<int> prc(n);
	for(int i = 0; i < n; i++){
		cin >> prc[i];
	}
	map<string, int> count;
	int temp = m;
	while(temp--){
		string s;
		cin >> s;
		count[s]++;
	}
	vector<int> freq;
	for(auto x: count){
		freq.push_back(x.second);
	}
	int low = 0;
	sort(prc.begin(), prc.end());
	sort(freq.begin(), freq.end());
	reverse(freq.begin(), freq.end());
	for(int i = 0; i < freq.size(); i++){
		low += prc[i]*freq[i];
	}
	reverse(prc.begin(), prc.end());
	int high = 0;
	for(int i = 0; i < freq.size(); i++){
		high += prc[i]*freq[i];
	}
	cout << low << " " << high << "\n";
}
