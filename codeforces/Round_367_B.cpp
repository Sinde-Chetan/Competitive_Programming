#include<bits/stdc++.h>

#define VEC vector<int>
#define REP(i, n) for(int i = 0; i < n; i ++)

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	scanf("%d", &n);
	VEC x(n);
	REP(i, n){
		scanf("%d\n", &x[i]);
	}
	sort(x.begin(), x.end());
	int q;
	scanf("%d", &q);
	while(q--){
		int m;
		scanf("%d", &m);
		int result = n;
		int left = 0, right = n-1;
		
		while(left <= right) {
			int mid = left + (right-left)/2;
			if(x[mid] > m){
				result = mid;
				right = mid - 1;
			}
			else{
				left = mid + 1;
			}
		}
		printf("%d\n", result);
	}
}
