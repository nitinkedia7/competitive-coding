#include <iostream>
using namespace std;
 
int main() {
    int n;
    cin >> n;
    int array[n];
    for (int i = 0; i < n; i++) cin >> array[i];

    if (n == 1) {
        cout << -1;
    }
    else if (n == 2 && array[0] == array[1]) {
        cout << -1 << endl;
    }
    else {
        cout << 1 << endl;
        int min = 0;
        for (int i = 0; i < n; i++) {
            if (array[min] > array[i]) min = i;
        }
        cout << min+1 << endl;
    }
}