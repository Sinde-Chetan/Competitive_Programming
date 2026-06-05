#include<iostream>
#include<vector>

using namespace std;

int main(){
    int N=4168;
    int zero_count=0;int arrow_point=50;
    for(int i=0;i<N;i++){
        char x;int y;cin>>x>>y;
        if(x=='L'){
            arrow_point-=y;
            if(arrow_point<0) arrow_point=(arrow_point+100)%100;
        }
        else if(x=='R'){
            arrow_point+=y;
            if(arrow_point>99) arrow_point=arrow_point%100;
        }
        else return 1;
        if(arrow_point==0) zero_count+=1;
    }
    cout<<zero_count;
}

