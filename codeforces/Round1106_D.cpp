#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (!(cin >> t)) return 0;
    
    vector<int> omega(1000005, 0);
    vector<int> distinct(1000005, 0);
    
    for (int i = 2; i < 1000005; i++) {
        if (distinct[i] == 0) {
            for (int j = i; j < 1000005; j += i) {
                distinct[j]++;
                int temp = j;
                while (temp % i == 0) {
                    omega[j]++;
                    temp /= i;
                }
            }
        }
    }
    
    while (t--) {
        int n;
        cin >> n;
        
        if (distinct[n] == 1) {
            cout << omega[n] << "\n";
        } else {
            cout << omega[n] + distinct[n] - 1 << "\n";
        }
    }
    
    return 0;
}
