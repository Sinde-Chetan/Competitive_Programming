#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int nod(int num){
    int N=num;
    int n=0;
    while(N!=0){
        n++;
	N=N/10;
    }
    return n;
}

int main(){
    int sum=0;
    while(1){
        char a,b;int x,y;
	cin>>a;
	if(a=='.') break;
	cin>>x>>b>>y;
	int n=x;
        while(n<=y){
	    int no_digits=nod(n);
	    int p=pow(10,no_digits/2);
	    if(n/p==n%p) sum+=n;
	    n++;
	}

    }
    cout<<sum;
}
