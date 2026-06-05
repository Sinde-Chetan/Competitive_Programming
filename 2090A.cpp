#include<iostream>
#include<vector>

using namespace std;

int main(){
    int t;cin>>t;
    vector<int>a;
    vector<int>x;
    vector<int>y;
    	for(int i=0;i<t;i++){
            long long int b,c,z;
	    cin>>b>>c>>z;
	    a.push_back(z);
	    x.push_back(b);
	    y.push_back(c);
    	}
    	for(int i=0;i<t;i++){
    	long long int day=1;
	double sum=0;
    	while(true){
            if(day%2!=0) sum+=x[i];
	    else sum+=y[i];
	    if(sum>a[i]) break;
	    day++;
    	}
    	if(day%2==0){
            cout<<"YES"<<endl;
    	}
	else cout<<"NO"<<endl;
    }
	return 0;
}
