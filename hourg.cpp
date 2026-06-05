#include<iostream>

using namespace std;

int main(){
    int t;cin>>t;
    int time[t];
    for(int i=0;i<t;i++){
        long int s,k,m;
	cin>>s>>k>>m;
	if(k>=m&&k>=s){
	    if(k==m) time[i]=s;
	    else if(s<=m) time[i]=0;
	    else time[i]=s-m;
	}
	else if(k>=s&&k<m){
	    int x=m%k;
	    if(x>=s) time[i]=0;
	    else time[i]=s-x;
	}
	else if(k<s&&k>=m){
	    if(k==m) time[i]=k;
	    else time[i]=s-m;
	}
	else{
	    int y=m/k;
	    if(y%2!=0) time[i]=k-(y%2);
	    else time[i]=s-(y%2);
	}
    }
    for(int i=0;i<t;i++){cout<<time[i]<<endl;}
}
