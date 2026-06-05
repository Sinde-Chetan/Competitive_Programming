#include<iostream>
#include<vector>

using namespace std;

void solve(vector<char> a, vector<char> b, int n){
	int count_a = 0;
	int count_b = 0;
	bool paired = false;
	for(int i = 0; i < n; i++){
		if(a[i] == b[i]){
			if(a[i] == '('){
				count_a++;
				count_b++;
			} 
			else{
				count_a--;
				count_b--;
			}
		}
		else{
			if(count_a <= count_b){
				count_a++;
				count_b--;
			}
			else{
				count_a--;
				count_b++;
			}
		}
		if(count_a < 0 || count_b < 0){
			paired = false;
			break;
		}
	}
	if(a[0] == ')' || b[0] == ')') paired = false;
	else if(a[n-1] == '(' || b[n-1] == '(') paired = false;
	else if(count_a == 0 && count_b == 0) paired = true;
	if(paired) cout << "YES" << endl;
	else cout << "NO" << endl;
}

int main(){
	int test;
	cin >> test;
	while(test--){
		int n;
		cin >> n;
		vector<char> a(n);
		vector<char> b(n);
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		for(int i = 0; i < n; i++){
			cin >> b[i];
		}
		solve(a, b, n);
	}
}
