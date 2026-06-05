#include<iostream>
#include<vector>

using namespace std;

int main(){
	int testcases;
	cin >> testcases;
	while(testcases--){
		int n;
		cin >> n;
		vector<char> parent_arr(n);
		int left_parent_count = 0;
		int right_parent_count = 0;
		for(int i = 0; i < n; i++) {
			cin >> parent_arr[i];
		}	
		for(int i = 0; i < n; i++){
			if(parent_arr[i] == '(') left_parent_count++;
			else if(parent_arr[i] == ')') right_parent_count++;
		}
		if(left_parent_count == right_parent_count) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}
