#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

#define all(x) (x).begin(), (x).end()


vector<tuple<int,int,int,int>> v;
vector<int> gone;

void handleXY(int l, int r) {
    int i = l;
    while (i < r) {
        int j = i;
        while (j < r && get<1> (v[i]) == get<1> (v[j])) {
            j++;
        }
        // if [i,j) is odd member one will survive others will go, even all go
        for (int k = i; k < j; k += 2) {
            if (k+1 == j) break;
            cout << get<3> (v[k]) << " " << get<3> (v[k+1]) << endl;
            gone[k] = 1;
            gone[k+1] = 1;
        }
        i = j; 
    }
    // [l, r) mein even pairs hatane se saare
    i = l;
    while (i < r) {
        if (gone[i] == 1) {
            i++;
            continue;
        }
        int j = i+1;
        while (j < r && gone[j] == 1) j++;
        if (j < r) {
            cout << get<3> (v[i]) << " " << get<3> (v[j]) << endl;
            gone[i] = 1;
            gone[j] = 1;
        } 
        i = j+1;
    }
    return;
}

void sherlock(int t) {
    int n;
    cin >> n;
    v.resize(n);
    int id = 0;
    for (auto &[x, y, z, i] : v) {
        cin >> x >> y >> z;
        i = ++id;
    }
    sort(all(v));
    int i = 0;
    gone.resize(n);
    fill(all(gone), 0);
    while (i < n) {
        int j = i;
        while (j < n && get<0> (v[i]) == get<0> (v[j])) {
            j++;
        }
        handleXY(i, j);
        i = j;
    }
    i = 0;
    while (i < n) {
        if (gone[i] == 1) {
            i++;
            continue;
        }
        int j = i+1;
        while (j < n && gone[j] == 1) j++;
        if (j < n) {
            cout << get<3> (v[i]) << " " << get<3> (v[j]) << endl;
            gone[i] = 1;
            gone[j] = 1;
        } 
        i = j+1;
    }
    return;
    assert(*min_element(all(gone)) == 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt = 1;
    // cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}