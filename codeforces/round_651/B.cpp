#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;

void sherlock(int t) {
    int n;
    cin >> n;
    int N = 2 * n, x;
    vector<int> odd, even;
    for (int i = 0; i < N; i++) {
        cin >> x;
        if (x % 2) {
            odd.push_back(i + 1);
        }
        else {
            even.push_back(i + 1);
        }
    }  
    if ((int) odd.size() == 0) {
        swap(odd, even);
    }  
    int ol = odd.size(), el = even.size();
    if (ol % 2 == 1) {
        for (int i = 0; i < ol - 1; i += 2) {
            cout << odd[i] << " " << odd[i+1] << endl;
        }
        for (int i = 0; i < el - 1; i += 2) {
            cout << even[i] << " " << even[i+1] << endl;
        }
    }
    else {
        for (int i = 0; i < ol - 2; i += 2) {
            cout << odd[i] << " " << odd[i+1] << endl;
        } 
        for (int i = 0; i < el; i += 2) {
            cout << even[i] << " " << even[i+1] << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}
