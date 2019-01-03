#include <iostream>
using namespace std;

int calclit(int *array, int n, int s, int e, int state, int memo[][2]) {
    if (memo[s][state] != -1 && e == n+1) return memo[s][state];
    if (s >= e) return 0;
    int temp = 0;
    if (state == 1) { // on
        temp = array[s+1] - array[s] + calclit(array, n, s+1, e, 0, memo);
    }
    else {
        temp = calclit(array, n, s+1, e, 1, memo);
    }
    if (e == n+1) memo[s][state] = temp;
    return temp;    
}

int func(int *array, int n, int s, int e, int state, int memo[][2]) {
    if (memo[e][state] != -1 && s == 0) return memo[e][state];
    if (s >= e) return 0;
    int temp = 0;
    if (state == 1) { // on
        temp = func(array, n, s, e-1, 0, memo);
    }
    else {
        temp = func(array, n, s, e-1, 1, memo) + array[e] - array[e-1];
    }
    if (s == 0) memo[e][state] = temp;
    return temp;    
}

int main() {
    int n, M;
    cin >> n >> M;

    int array[n+2];
    array[0] = 0;
    array[n+1] = M;
    for (int i = 1; i < n+1; i++) {
        cin >> array[i];
    }
    int memo[n+2][2];

    for (int i = 0; i < n+2; i++) {
        memo[i][0] = -1;
        memo[i][1] = -1;
    }
    memo[n+1][0] = 0;
    memo[n+1][1] = 0;

    int mem[n+2][2];

    for (int i = 0; i < n+2; i++) {
        mem[i][0] = -1;
        mem[i][1] = -1;
    }
    mem[0][0] = 0;
    mem[0][1] = 0;

    memo[0][1] = calclit(array, n, 0, n+1, 1, memo);
    mem[n+1][0]
    // insert x;
    int ans[n+1];
    for (int i = 0; i < n+1; i++) {
        if (array[i+1] - array[i] > 1) {
            if (i%2 == 0) {
                ans[i] = calclit(array, n, 0, i, 1, memo) + array[i+1] - 1 - array[i] + calclit(array, n, i+1, n+1, 1, memo);
            }
            else {
                ans[i] = calclit(array, n, 0, i, 1, memo) + array[i+1] - 1 - array[i] + calclit(array, n, i+1, n+1, 0, memo);
            }
        }
        else ans[i] = -1;
    }
    int max = memo[0][1];
    // cout << max << '\n';

    for (int i = 0; i < n+1; i++) {
        if (ans[i] > max) {
            max = ans[i];
            // cout << i << endl;
        }
    }
    cout << max << '\n';
    return 0;
}