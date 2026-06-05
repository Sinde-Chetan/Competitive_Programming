#include<iostream>

using namespace std;

int main(){
    int t; cin>>t;
    int diff[t];
    for(int i=0;i<t;i++){
    	long int n;cin>>n;
	if(n%6==1 || n%6==5) diff[i]=1;
	else if(n%6==2) diff[i]=2;
	else if(n%6==3) diff[i]=3;
	else diff[i]=0;
    }
    for(int i=0;i<t;i++){cout<<diff[i]<<endl;}
}
