#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        long long n;
        cin >> n;

        vector<long long> a(n);

        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
	long long coins = 0;
	long long neg_start = 0;
	long long pos_end = n-1;
	for(int i = 0; i < n; i++){
		long long move = 0;
		if(a[neg_start] >= 0) neg_start++;
		if(a[pos_end] <= 0) pos_end--;
		if(neg_start < pos_end){
			move = min(a[pos_end], -a[neg_start]);
			a[neg_start] += move;
			a[pos_end] -= move;
			coins += move;
		}  
	}
	cout << coins << "\n";
}
}
