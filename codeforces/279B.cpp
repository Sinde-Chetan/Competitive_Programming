#include<bits/stdc++.h>

using namespace std;

int main() {
	int l = 0;
	long long sum = 0;
	int ans = 0;

	for (int r = 0; r < n; r++) {
    	sum += a[r];

    	while (sum > t) {
        	sum -= a[l];
        	l++;
    	}

    	ans = max(ans, r - l + 1);
	}

	cout << ans << '\n';
}


