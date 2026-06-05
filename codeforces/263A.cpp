#include<iostream>

using namespace std;

int main(){
    int bm[5][5];
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
	    int x;cin>>x;
	    bm[i][j]=x;
	}
    }
    int i,j;
    bool found=false;
    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
	    if(bm[i][j]==1){
	        found=true;
		break;
	    }
	}
       if(found) break;	
    }
    int moves=0;
    if(i+2==2||i-2==2) moves=moves+2;
    else if(i+1==2||i-1==2) moves=moves+1;
    if(j+2==2||j-2==2) moves=moves+2;
    else if(j+1==2||j-1==2) moves=moves+1;
    cout<<moves; 
}
