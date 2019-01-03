#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int array[101];
    for (int i = 0; i < 101; i++) {
        array[i] = 0;
    }
    int temp;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        array[temp] = i+1;
    }

    vector<int> v;
    int index = 0;
    for (int i = 0; i < 101; i++) {
        if (array[i] != 0) {
            v.push_back(array[i]);
            index++;
        }
    }
    if (index >= k) {
        cout << "YES" << endl;
        for (int i = 0; i < k; i++) {
            cout << v[i] << " ";
        }
        cout << endl;
    }
    else cout << "NO" << endl;

}