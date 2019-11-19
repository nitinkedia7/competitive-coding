#include <bits/stdc++.h>
using namespace std;

int main() {
    srand(time(0));
    int n;
    cin >> n;
    int k = rand() % n + 1;
    cout << 1 << endl;
    cout << n << " " << k << endl;
    for (int i = 0; i < n; i++) {
        cout << (rand() % 100000) + 1 << " ";
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << (rand() % 1000) + 1 << " ";
    }
    cout << endl;
}