#include<iostream>
using namespace std;

int main(){
    int sum = 0;

    while(1){
        char a, b;
        int x, y;

        cin >> a;
        if(a == '.') break;
        cin >> x >> b >> y;
        for(int digits = 2; digits <= 10; digits += 2){
            int half = digits / 2;
`
            int start = 1;
            for(int i = 1; i < half; i++) start *= 10;

            int end = start * 10 - 1;

            int p = 1;
            for(int i = 0; i < half; i++) p *= 10;

            for(int A = start; A <= end; A++){
                int num = A * p + A;

                if(num >= x && num <= y){
                    sum += num;
                }
            }
        }
    }

    cout << sum;
}
