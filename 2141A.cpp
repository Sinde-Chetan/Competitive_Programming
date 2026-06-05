#include<iostream>
#include<vector>

using namespace std;

int main(){
int t;cin>>t;
vector<int>a;
for(int i=0;i<t;i++){
    	int n;
    	cin>>n;
    	for(int j=0;j<n;j++){
            int x;cin>>x;
	    a.push_back(x);
    	}
        vector<int>b;
        int count=0;
        for(int i=1;i<n;i++){
            int index=0;
	    bool found=true;
	    while(index<i){
	    	if(a[index]<a[i]){
	    	    found=false;
		    b.push_back(i+1);
		    break;
	    	}
	        index++;
	    }
	    if(!found) count++;
        }
        cout<<count<<endl;
        for(int i=0;i<b.size();i++){
            cout<<b[i]<<" ";
        }
	cout<<endl;
	a.clear();
    }
}
