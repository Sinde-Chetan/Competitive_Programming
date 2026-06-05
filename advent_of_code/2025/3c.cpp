#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> nums;
vector<long long> prefix;

// generate all valid numbers
void generate(){
    for(int digits = 2; digits <= 10; digits += 2){
        int half = digits / 2;

        int start = 1;
        for(int i = 1; i < half; i++) start *= 10;

        int end = start * 10 - 1;

        int p = 1;
        for(int i = 0; i < half; i++) p *= 10;

        for(int A = start; A <= end; A++){
            int num = A * p + A;
            nums.push_back(num);
        }
    }

    sort(nums.begin(), nums.end());

    // prefix sum
    prefix.resize(nums.size());
    prefix[0] = nums[0];
    for(int i = 1; i < nums.size(); i++){
        prefix[i] = prefix[i-1] + nums[i];
    }
}

int main(){
    generate();

    while(1){
        char a, b;
        int x, y;

        cin >> a;
        if(a == '.') break;

        cin >> x >> b >> y;

        // find range using binary search
        auto it1 = lower_bound(nums.begin(), nums.end(), x);
        auto it2 = upper_bound(nums.begin(), nums.end(), y);

        if(it1 == nums.end() || it1 >= it2){
            cout << 0 << endl;
            continue;
        }

        int l = it1 - nums.begin();
        int r = (it2 - nums.begin()) - 1;

        long long ans = prefix[r];
        if(l > 0) ans -= prefix[l-1];

        cout << ans << endl;
    }
}
