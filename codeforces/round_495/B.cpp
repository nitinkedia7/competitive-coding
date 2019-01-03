#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    pair<int, int> arr[m];
    for (int i = 0; i < m; i++) {
        cin >> arr[i].first >> arr[i].second;
    }
    for (int i = 0; i < n; i++) {
        cout << i%2;
    }
    cout << "\n";
    return 0;
}