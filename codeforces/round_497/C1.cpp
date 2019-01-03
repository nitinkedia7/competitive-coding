#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    int n;
    cin >> n;
    int array[n];
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }
    sort(array, array+n);

    queue<int> q;
    int m = 0;
    for (int i = 0; i < n; i++) {
        if (q.empty()) {
            q.push(array[i]);
        } 
        else {
            if (q.front() < array[i]) {
                m++;
                q.pop();
                q.push(array[i]);
            }
            else {
                q.push(array[i]);
            }
        }
    }
    cout << m << endl;
}