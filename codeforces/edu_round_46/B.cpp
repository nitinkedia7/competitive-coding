#include <iostream>
using namespace std;

int main() {
    int n, M;
    cin >> n >> M;

    int array[n+2];
    array[0] = 0;
    array[n+1] = M;
    for (int i = 1; i < n+1; i++) {
        cin >> array[i];
    }
    int ua = 0;
    for (int i = 0; i < n+2; i++) {
        if (i == n+1 && n%2 == 1) break;
        if (i%2 == 1) {
            ua += array[i] - array[i-1];
        }
    }
    // insert x;
    int ans[n+1];
    int a = 0;
    for (int i = 0; i < n; i++) {
        if (array[i+1] - array[i] == 1) {
            ans[i] = ua;
        }
        else {
            a = 0;
            for (int j = 0; j <= i; j++) {
                if (j%2 == 1) a += array[j] - array[j-1]; 
            }
            if (i % 2 == 1) a += array[i+1] - 1 - array[i];
            else {

            }
            for (int i = i+2; i < n+2; i++) {
                if (i == n+1 && n%2 == 0) break;
                if (i % 2 == 0) {
                    a += array[i] - array[i-1];
                }
            }
            ans[i] = a;
            break;
        }
    }
    for (int i = 1; i < n; i++) {
        if (array[i+1] - array[i] != 1) {
            if (i % 2 == 1) {
                ans[i] = ans[i-1];
            }
            else {
                ans[i] = ans[i-1] + array[i-1] + array[i+1] - 2*array[i];
            }
        }
        else ans[i] = ans[i-1];
    }
    if (array[n+1] - array[n] > 1) {
        if (n%2 == 0) {
            ans[n] = a + array[n+1] - array[n] - 1; 
        }
        else {
            ans[n] = a - 1;
        }
    }
    else ans[n] = a;

    int max = ans[0];
    for (int i = 0; i < n+1; i++) {
        if (ans[i] > max) max = ans[i];
    }
    if (ua > max) max = ua;
    cout << max << endl;
    return 0;
}