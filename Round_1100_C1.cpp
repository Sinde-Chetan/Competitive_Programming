#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    int test;
    cin >> test;

    while (test--) {

        int n;
        cin >> n;

        vector<long long> arr(n);

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        vector<int> operations;

        bool flipped = false;

        for (int i = n - 1; i >= 0; i--) {

            long long current = arr[i];

            if (flipped) {
                current = -current;
            }

            if (current > 0) {

                operations.push_back(i + 1);

                flipped = !flipped;
            }
        }

        reverse(operations.begin(), operations.end());

        cout << operations.size() << endl;

        for (int x : operations) {
            cout << x << " ";
        }

        cout << endl;
    }
}
