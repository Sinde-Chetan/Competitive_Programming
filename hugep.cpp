#include<iostream>

using namespace std;

void piling1(int piles,int app,int timereq1[],int i,int k){
    if(piles==app) {
	    timereq1[k]=i;
	    return;
    }
    else if(piles<app) {
	    timereq1[k]=-1;
	    return;
    }
    piling1(piles/2,app,timereq1,i+1,k);
}
void piling2(int piles,int app,int timereq2[],int i,int k){
    if(piles==app) {
	    timereq2[k]=i;
	    return;
    }
    else if(piles<app) {
	    timereq2[k]=-1;
	    return;
    }
    if(piles%2==0) piling2(piles/2,app,timereq2,i+1,k);
    else piling2((piles/2)+1,app,timereq2,i+1,k);
}

int main(){
    int t;cin>>t;
    int time1[t];
    int time2[t];
    for(int i=0;i<t;i++){
        long int n,k;
	cin>>n>>k;
	piling1(n,k,time1,0,i);
	piling2(n,k,time2,0,i);
    }
    for(int i=0;i<t;i++){
        if(time1[i]==-1&&time2[i]==-1) cout<<-1<<endl;
	else if(time1[i]==-1 || time2[i]==-1) cout<<max(time1[i],time2[i])<<endl;
	else cout<<min(time1[i],time2[i])<<endl;
    }
}
