#include<iostream>
#include<vector>

using namespace std;

void solution(vector<int> vec, int n){
	vector<int> result;
	for(int i: vec){
		if(i%6 == 0) result.push_back(i);
	}
	for(int i: vec){
		if(i%2 == 0 && i%3 != 0) result.push_back(i);
	}
	for(int i: vec) {
		if(i%2 != 0 && i%3 != 0) result.push_back(i);
	}
	for(int i: vec){
		if(i%2 != 0 && i%3 == 0) result.push_back(i);
	}
	for(int j: result){
		cout << j << " ";
	}
}

int main(){
	int testcases;
	cin >> testcases;
	while(testcases--){
		int n;
		cin >> n;
		vector<int> seq(n);
		for(int i = 0; i < n; i++){
			cin >> seq[i];
		}
		
		solution(seq, n);
	}
}
