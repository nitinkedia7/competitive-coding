#include <iostream>
#include <algorithm>
using namespace std;
 
int main() {
    int n;
    cin >> n;
    int array[n], index[n];
    int sum = 0;
    for (int i = 0; i < n; i++)  {
        cin >> array[i];
        sum += array[i];
    }
    int a = 0;
    for (int i = 0; i < n; i++) {
        a += array[i];
        
        if (2*a > sum) {
            cout << i+1 << endl;
            for (int j = 0; j < i; j++) {
                cout << j+1 << " ";
            }
            cout << endl;
            return 0;
        }
    }
    cout << 
}