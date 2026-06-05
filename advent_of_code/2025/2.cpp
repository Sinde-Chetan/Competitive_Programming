#include<iostream>
#include<vector>

using namespace std;

int main(){
    int N=4168;
    int zero_count=0;int arrow_position=50;
    for(int i=0;i<N;i++){
        char x;int y;cin>>x>>y;
        if(x=='L'){
            for(int i=0;i<y;i++){
	        arrow_position-=1;
		if(arrow_position<0) arrow_position+=100;
		if(arrow_position==0) zero_count++;
	    }
        }
        else if(x=='R'){
            for(int i=0;i<y;i++){
	        arrow_position+=1;
		if(arrow_position>99) arrow_position-=100;
		if(arrow_position==0) zero_count++;
	    }
        }
        else return 1;
    }
    cout<<zero_count;
}

