#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;

bool can_make(int l, int k, vector<int> count) {
    vector<int> done(l, 0), sets;
    for (int i = 0; i < l; i++) {
        if (done[i]) continue;
        int s = i, c = 0;
        while (!done[s]) {
            c++;
            done[s] = 1;
            s = (s + k) % l;
        }
        sets.push_back(c);
    }
    // satisfy smallest first
    sort(all(sets));
    for (auto s : sets) {
        // find min elem in count >= s
        int mfi = -1;
        for (int i = 0; i < 26; i++) {
            if (count[i] < s) continue;
            if (mfi == -1 || count[i] < count[mfi]) {
                mfi = i;
            }
        }
        if (mfi == -1) return false;
        count[mfi] -= s;
    }
    return true;
}

void sherlock(int t) {
    int n, k;
    cin >> n >> k;
    vector<int> count(26);
    char x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        count[x - 'a']++;
    }   
    int l;
    for (l = n; l > 0; l--) {
        if (can_make(l, k, count)) {
            break;
        }
    }
    cout << l << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}
