#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    int array[n];
    for (int i = 0; i < n; i++) cin >> array[i];
    int ans[n];
    for (int i = 0; i < n; i++) {
        ans[i] = array[i] + (i - array[i]%n + n)%n;;
    }
    int min = 0;
    for (int i = 0; i < n; i++) {
        if (ans[i] < ans[min]) min = i;
    }
    cout << min+1 << endl;
    return 0;
}