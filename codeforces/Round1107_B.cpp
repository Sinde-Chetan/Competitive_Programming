#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (cin >> t) {
        while (t--) {
            long long x;
            cin >> x;
            
            long long y = 2;
            while (y <= 20000) {
                int mask_y = 0;
                long long temp_y = y;
                while (temp_y > 0) {
                    mask_y |= (1 << (temp_y % 10));
                    temp_y /= 10;
                }
                
                int mask_xy = 0;
                long long temp_xy = x * y;
                while (temp_xy > 0) {
                    mask_xy |= (1 << (temp_xy % 10));
                    temp_xy /= 10;
                }
                
                if (__builtin_popcount(mask_y) <= 2 && __builtin_popcount(mask_xy) <= 2) {
                    cout << y << "\n";
                    break;
                }
                
                y++;
            }
        }
    }
    return 0;
}
