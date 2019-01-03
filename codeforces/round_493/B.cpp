#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
 
int main() {
    int n, b;
    cin >> n >> b;
    int array[n];
    for (int i = 0; i < n; i++) cin >> array[i];
    int o = 0, e = 0, c = 0;
    vector<int> v1;
    for (int i = 0; i < n; i++) {
        if (array[i]%2 == 0) {
            e++;
        }
        else o++;
        if (o == e && i != n-1) {
            // v.push_back(i);
            v1.push_back(abs(array[i+1]-array[i]));
            c++;
            e = 0;
            o = 0;
        }
    }
    if (c > 0) sort(v1.begin(), v1.end());
    int sum = 0;
    for (int i = 0; i < c; i++) {
        sum += v1[i];
        if (sum > b) {
            cout << i << endl;
            return 0;
        }
        else if (sum == b) {
            cout << i+1 << endl;
            return 0;
        }
    }
    if (sum < b) cout << c << endl;
    else cout << 0 << endl;
    return 0;
}

