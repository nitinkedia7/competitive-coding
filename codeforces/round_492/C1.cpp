#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void swap(int *array, int n, int s, int *c) {
    if (s == 2*n-2) return;

    int pos;
    for (int i = s+1; i < 2*n; i++) {
        if (array[s] == array[i]) {
            pos = i;
            break;
        }
    }
    for (int i = pos; i > s+1; i--) {
        array[i] = array[i-1];
        *c = *c + 1;
    }
    array[s+1] = array[s];
    // for (int i = 0; i < 2*n; i++) cout << array[i] << " ";
    // cout << '\n';
    swap(array, n, s+2, c);
    return; 
}

int main() {
    int n;
    cin >> n;
    int array[2*n];
    for (int i = 0; i < 2*n; i++) cin >> array[i];
    int c = 0;
    swap(array, n, 0, &c);
    // for (int i = 0; i < 2*n; i++) cout << array[i] << " ";
    // cout << '\n';
    cout << c << '\n';
}