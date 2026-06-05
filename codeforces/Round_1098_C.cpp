#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

int main(){
	int test;
	cin >> test;
	while(test--){
		long long int a;
		int n;
		cin >> a >> n;
		vector<int> d(n);
		for(int i = 0; i < n; i++){
			cin >> d[i];
		}
		long long temp_dig = a;
		vector<int> digits;
		if(a == 0){
		        digits.push_back(0);
		}
		else{
			while(temp_dig){
				digits.push_back(temp_dig % 10);
				temp_dig = temp_dig/10;
			}
		}

		reverse(digits.begin(), digits.end());

		vector<int> digits_1;
		vector<int> digits_2;
		for(int i: digits){
			if(i == digits[0]){
				if(abs(d[0]-i) == abs(d[1]-i)) {
					if(d[0] < d[1]) {
						digits_1.push_back(d[0]);
						digits_2.push_back(d[1]);
					}
					else {
						digits_1.push_back(d[1]);
					}		digits_2.push_back(d[0]);
				}
				else if(abs(d[0]-i) < abs(d[1]-i)){
				                digits_1.push_back(d[0]);
				                digits_2.push_back(d[0]);
				}
				else{
				                digits_1.push_back(d[1]);
				                digits_2.push_back(d[1]);
				}
			}
			else{
                                if(abs(d[0]-i) == abs(d[1]-i)) {
                                        if(d[0] > d[1]) {
                                                digits_1.push_back(d[0]);
                                                digits_2.push_back(d[1]);
                                        }
                                        else {
                                                digits_1.push_back(d[1]);
                                        }               digits_2.push_back(d[0]);
                                }
				else if(abs(d[0]-i) < abs(d[1]-i)) {
					digits_1.push_back(d[0]);
					digits_2.push_back(d[0]);
				}
				else{
					digits_1.push_back(d[1]);
					digits_2.push_back(d[1]);
				}
			}

		}

		long long n1 = 0;

		for(int i: digits_1){
			n1 += i;
			n1 = n1*10;
		}
		n1 = n1/10;

		long long n2 = 0;

		for(int i: digits_2){
			n2 += i;
			n2 = n2*10;
		}
		n2 = n2/10;

		long long int min1 = abs(n1-a) < abs(n2-a) ? abs(n1-a) : abs(n2-a);
		
		int max_d = max(d[0],d[1]);
		
        long long min2 = (long long)4e18;

        if(digits.size() > 1){
        long long n3 = 0;

        for(int i = 0; i < (int)digits.size() - 1; i++){
            n3 = n3 * 10 + max_d;
        }

        min2 = llabs(a - n3);
    }
		long long int result = min1 < min2 ? min1 : min2;

		cout << result << endl;		
	}
}
