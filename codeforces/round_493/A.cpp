#include <iostream>
using namespace std;

bool divide(int sum, int *array, int n, int *index) {
    if (sum == 0) return true;
    else if (sum < 0) return false;
    if (n < 0) return false;
    if (divide(sum, array, n-1, index)) {
        return true;
    }
    if (divide(sum-array[n], array, n-1, index)) {
        index[n] = 1;
        return true;
    }
    return false;
}
 
int main() {
    int n;
    cin >> n;
    int array[n], index[n];
    int sum = 0;
    for (int i = 0; i < n; i++)  {
        cin >> array[i];
        sum += array[i];
    }
    for (int i = 0; i < n; i++) index[i] = 0;
    if (sum % 2 == 0) {
        bool ans = divide(sum/2, array, n-1, index);
        if (ans) {
            int k = 0;
            for (int i = 0; i < n; i++) k += index[i];
            cout << k << endl;
            for (int i = 0; i < n; i++) {
                if (index[i] == 1) cout << i+1 << " ";
            }
            cout << endl;
        }
        else cout << -1 << endl;
    }
    else cout << -1 << endl;
    return 0;
}