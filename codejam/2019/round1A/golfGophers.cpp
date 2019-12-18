#include <bits/stdc++.h>
using namespace std;
vector<int> coprimes = {16, 9, 5, 7, 11, 13, 17};
vector<int> res(7);

bool satisfiesMod(int x) {
    for (int i = 0; i < 7; i++) {
        if (x % coprimes[i] != res[i]) return false;
    }
    return true;
}

bool scan(int &x) {
    cin >> x;
    if (x == -1) exit(0);
}

void sherlock() {
    int temp;
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 18; j++) {
            cout << coprimes[i] << " ";
        }
        cout << endl;
        int sum = 0;
        for (int j = 0; j < 18; j++) { 
            scan(temp);
            sum += temp;
        }
        res[i] = sum % coprimes[i];
    }
    int N = 1e6+1;
    for (int i = 0; i < N; i++) {
        if (!satisfiesMod(i)) continue;
        cout << i << endl;
        scan(temp);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, n, m;
    cin >> t >> n >> m;
    for (int i = 0; i < t; i++) sherlock();
    return 0;
}