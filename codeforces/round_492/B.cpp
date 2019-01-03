#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int array[n];
    for (int i = 0; i < n; i++) cin >> array[i];
    int t = 0;
    while (1) {
        if (array[t%n] <= t) {
            cout << t%n + 1 << endl;
            return 0;
        }
        t++;
    }
    cout << "Bingo" << endl;
}