#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;

void sherlock(int t) {
    int n;
    cin >> n;
    vector<int> b(n);
    vector<pair<int,int>> b_p(n);
    vector<int> r_b(2 * n + 1);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        b_p[i] = {b[i], i};
        r_b[b[i]] = i;
    }    
    vector<int> p(2 * n + 1, 0), a(2 * n);
    for (int i = 0; i < n; i++) {
        if (p[b[i]] == 1) {
            cout << -1 << endl;
            return;
        }
        a[2 * i] = b[i];
        p[b[i]] = 1;
    }
    sort(all(b_p));
    int x = 0;
    // vector<int> rem;
    for (int i = 1; i <= 2 * n; i++) {
        if (p[i] == 1) continue;
        // i is minimum available number
        if (b_p[x].first > i) {
            // cout << b_p[x].first << " " << b_p[x].second << " " << i << endl;
            cout << -1 << endl;
            return;
        }
        // rem.push_back(i);
        // a[2 * b_p[x].second + 1] = i;
        // p[i] = 1;
        x++;
    }
    int d = 0, r = 0;
    vector<int> z, rem;
    for (int i = 1; i <= 2 * n; i++) {
        if (p[i]) {
            d++;
            z.push_back(r_b[i]);
        }
        else {
            r++;
            rem.push_back(i);
        }
        if (d == r) {
            sort(all(z));
            for (int j = 0; j < d; j++) {
                a[2 * z[j] + 1] = rem[j];
            }
            d = 0;
            r = 0;
            z.clear();
            rem.clear();
        }
    }
    for (int i = 0; i < 2 * n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}   

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}


#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;

void print(vector<int> &v) {
    for (int i = 0; i < (int) v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

void sherlock(int t) {
    int n;
    cin >> n;
    vector<int> b(n);
    vector<pair<int,int>> b_p(n);
    vector<int> r_b(2 * n + 1);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        b_p[i] = {b[i], i};
        r_b[b[i]] = i;
    }    
    vector<int> p(2 * n + 1, 0), a(2 * n);
    for (int i = 0; i < n; i++) {
        if (p[b[i]] == 1) {
            cout << -1 << endl;
            return;
        }
        a[2 * i] = b[i];
        p[b[i]] = 1;
    }
    sort(all(b_p));
    int x = 0;
    vector<int> done;
    for (int i = 1; i <= 2 * n; i++) {
        if (p[i] == 1) {
            done.push_back(i);
            continue;
        }
        // i is minimum available number
        if (b_p[x].first > i) {
            // cout << b_p[x].first << " " << b_p[x].second << " " << i << endl;
            cout << -1 << endl;
            return;
        }
        // rem.push_back(i);
        // a[2 * b_p[x].second + 1] = i;
        // p[i] = 1;
        x++;
    }

    int i = 1;
    x = 0;
    while (i <= 2 * n) {
        if (p[i] == 1) {
            i++;
            continue;
        }
        vector<int> rem, z;
        int j = i;
        while (j <= 2 * n && p[j] == 0) {
            rem.push_back(j);
            j++;
        }
        // build z
        for (int k = 0; k < (int) rem.size(); k++) {
            z.push_back(r_b[done[x]]);
            x++;
        }
        sort(all(z));
        for (int k = 0; k < (int) z.size(); k++) {
            a[2 * z[k] + 1] = rem[k];
        }
        print(rem);
        print(z);
        cout << endl;
        i = j;
    } 
    for (int i = 0; i < 2 * n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}   

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}
