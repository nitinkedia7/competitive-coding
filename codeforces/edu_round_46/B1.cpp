#include <iostream>
using namespace std;

int calclit(int *array, int s, int e, int state, pair<int, int> **memo) {
    if (state == 1) {
        if (memo[s][e].second != -1) return memo[s][e].second;
    }
    else if (memo[s][e].first != -1) return memo[s][e].first;

    if (state == 1) { // on
        memo[s][e].second = array[s+1] - array[s] + calclit(array, s+1, e, 0, memo);
        return memo[s][e].second;
    }
    else {
        memo[s][e].first = calclit(array, s+1, e, 1, memo);
        return memo[s][e].first;    
    }
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
    // pair<int, int> memo[n+2][n+2];
    pair<int, int>** memo = new pair<int, int>*[n+2];
    for (int i = 0; i < n+2; i++) {
        memo[i] = new pair<int, int>[n+2];
    }

    for (int i = 0; i < n+2; i++) {
        for (int j = 0; j < n+2; j++) {
            memo[i][j] = make_pair(-1, -1);
        }
    }
    for (int i = 0; i < n+2; i++) {
        memo[i][i] = make_pair(0, 0);
    }
    memo[0][n+1].second = calclit(array, 0, n+1, 1, memo);
    // insert x;
    int ans[n+1];
    for (int i = 0; i < n+1; i++) {
        if (array[i+1] - array[i] > 1) {
            if (i%2 == 0) {
                ans[i] = calclit(array, 0, i, 1, memo) + array[i+1] - 1 - array[i] + calclit(array, i+1, n+1, 1, memo);
            }
            else {
                ans[i] = calclit(array, 0, i, 1, memo) + array[i+1] - 1 - array[i] + calclit(array, i+1, n+1, 0, memo);
            }
        }
        else ans[i] = -1;
    }
    int max = memo[0][n+1].second;
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