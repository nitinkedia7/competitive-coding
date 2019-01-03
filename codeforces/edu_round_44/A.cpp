#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    int n;
    cin >> n;
    int m = n/2;
    int pos[m];
    for (int i = 0; i < m; i++) {
        cin >> pos[i];
    }
    int b = 0, w = 0;
    int pos_b = 1, pos_w = 2;
    for (int i = 0; i < m; i++) {
        b += abs(pos[i]-pos_b);
        w += abs(pos[i]-pos_w);
        // cout << b << endl;
        // cout << w << endl;
        pos_b += 2;
        pos_w += 2;
    }
    if (b < w) cout << b << endl;
    else cout << w << endl;       
}