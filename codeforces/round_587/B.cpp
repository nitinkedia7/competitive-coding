#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int,int>> v(n);
    int d;
    for (int i = 0; i < n; i++) {
        cin >> d;
        v[i] = {d, i};
    }
    sort(v.begin(), v.end(), greater<pair<int,int>>());
    long long shots = 0;
    for (int i = 0; i < n; i++) {
        shots += (1 + v[i].first * i);
    }
    cout << shots << endl;
    for (int i = 0; i < n; i++) {
        cout << v[i].second + 1 << " ";
    }
    cout << endl;
    return 0;
}