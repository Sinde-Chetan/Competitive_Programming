#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void solve(vector<int> vec, int n){

    if(n == 1){
        cout << "YES" << endl;
        return;
    }
    bool sorted = false;
    vector<int> diff(n-1);
    for(int i = 0; i < n-1; i++){
        diff[i] = vec[i] - vec[i+1];
    }
    int mx = *max_element(diff.begin(), diff.end());

    for (int i = 0; i < diff.size(); i++){
        if(diff[i] > 0) diff[i] -= mx;
        if(diff[i] < 0) diff[i] += mx;
    }
    if(diff[diff.size()-1] > 0) diff[diff.size()-1] -= mx;

    mx = *max_element(diff.begin(), diff.end());
    if(mx <= 0) {
        sorted = true;
        cout << "YES" << endl;
        return;
    }
    cout << "NO" << endl;
    return;

}

int main(){
    int testcases;
    cin >> testcases;
    while(testcases > 0){
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }
        testcases--;

        solve(arr, n);
    }

    // vector<int> arr = {8 ,3 ,9 ,4 ,10 ,5 ,11};
    // solve(arr, n);
}