#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int array[n];
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }
    sort(array, array+n);
    int scope = 1, count = 0;
    for (int i = 0; i < n; i++) {
        scope = max(scope, i+1);
        for (int j = scope; j < n; j++) {
            if (array[j] != array[i]) {
                scope = j;
                if (array[j] <= array[i] + k) {
                    count++;
                    // cout << array[i] << " " << array[j] << endl;
                }
                // scope = j;
                break;
            }
            // scope++;
        }
    }
    cout << n-count << endl;
}