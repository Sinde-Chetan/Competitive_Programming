#include<iostream>

using namespace std;

int main(){
    int n;cin>>n;
    int X=0,Y=0,Z=0;
    while(n>0){
        int x,y,z;cin>>x>>y>>z;
	X=X+x;Y=Y+y;Z=Z+z;
	n--;
    }
    if(X==0 && Y==0 && Z==0) cout<<"YES";
    else cout<<"NO";
}
