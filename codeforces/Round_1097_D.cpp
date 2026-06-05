#include<iostream>
#include<vector>

using namespace std;

const long long MOD = 998244353;

long long power(long long a, long long b){
    long long res = 1;

    while(b){
        if(b & 1) res = (res * a) % MOD;

        a = (a * a) % MOD;
        b >>= 1;
    }

    return res;
}

void solve(vector<long long> a, vector<long long> b, int n){

    long long sum = 0;

    long long denom = 1LL * n * (n - 1);

    long long inv = power(denom % MOD, MOD - 2);

    for(int i = 0; i < n; i++){

        for(int j = i + 1; j < n; j++){

            long long count = 0;

            for(int p = 0; p < n; p++){

                for(int q = 0; q < n; q++){

                    if(p == q) continue;

                    if(a[i] * b[p] > a[j] * b[q]){
                        count++;
                    }
                }
            }

            sum = (sum + count * inv) % MOD;
        }
    }

    cout << sum % MOD << endl;
}

int main(){

    int test;
    cin >> test;

    while(test--){

        int n;
        cin >> n;

        vector<long long> a(n);
        vector<long long> b(n);

        for(int i = 0; i < n; i++){
            cin >> a[i];
        }

        for(int i = 0; i < n; i++){
            cin >> b[i];
        }

        solve(a, b, n);
    }
}
