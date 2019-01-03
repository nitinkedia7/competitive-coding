#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair <int, int>> v(n);
    int w,h;
    for (int i = 0; i < n; i++) {
        cin >> w >> h;
        v[i] = make_pair(w,h);
    }
    int p;
    if (v[0].first > v[0].second) p = v[0].first;
    else p = v[0].second;

    for (int i = 1; i < n; i++) {
        if (v[i].first > v[i].second) {
            if (p >= v[i].first) p = v[i].first;
            else if (p >= v[i].second) p = v[i].second;
            else {
                cout << "NO" << endl;
                return 0;
            }
        }
        else {
            if (p >= v[i].second) p = v[i].second;
            else if (p >= v[i].first) p = v[i].first;
            else {
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    cout << "YES" << endl;
}
