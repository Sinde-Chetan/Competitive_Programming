#include<bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<int> a(2*n);
		vector<int> L(n, -1), R(n);
		for(int i = 0 ; i < 2*n ; i++){
			int x;
			cin >> x;
			a[i] = x;
			if(L[x] == -1) L[x] = i;
			else R[x] = i;
		}
		int l = L[0];
		int r = R[0];
		int left = L[0];
		int right = R[0];
		vector<int> pal1;
		bool pal = true;
		while(left <= right){
			if(a[left] == a[right]){
				left++;
				right--;
			}
			else{
				pal = false;
				break;
			}
		}
		if(pal){
			while(l >= 0 && r < 2*n){
				if(a[l] == a[r]){
					l--;
					r++;
				}
				else break;
			}
			for(int i = l+1; i <= r-1; i++){
				pal1.push_back(a[i]);
			}
		}
		else pal1.push_back(0);
		
		vector<int> pal2;
		if(L[0] - 1 >= 0){
			l = L[0]-1;
			r = L[0]+1;
			while(l >= 0 && r < 2*n){
				if(a[l] == a[r]){
					l--;
					r++;
				}
				else break;
			}
			for(int i = l+1; i <= r-1; i++){

				pal2.push_back(a[i]);
			}
		}
		else pal2.push_back(0);

		vector<int> pal3;
		if(R[0]+1 < 2*n){;
			l = R[0] - 1;
			r = R[0] + 1;
			while(l >= 0 && r < 2*n){
				if(a[l] == a[r]){
					l--;
					r++;
				}
				else break;
			}
			for(int i = l+1; i <= r-1; i++){
				pal3.push_back(a[i]);
			}
		}
		else pal3.push_back(0);

		set<int> st1;
		for(int i = 0; i < pal1.size(); i++){
			st1.insert(pal1[i]);
		}
		set<int> st2;
		for(int i = 0; i < pal2.size(); i++){
			st2.insert(pal2[i]);
		}
		set<int> st3;
		for(int i = 0; i < pal3.size(); i++){
			st3.insert(pal3[i]);
		}
		int mex1 = 0;
		while(st1.count(mex1)) mex1++;

		int mex2 = 0;
		while(st2.count(mex2)) mex2++;

		int mex3 = 0;
		while(st3.count(mex3)) mex3++;

		cout << max({mex1, mex2, mex3}) << "\n";

	}
}
