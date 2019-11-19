#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void sherlock(int t) {
    int n;
    cin >> n;
    vector<int> eat(n), energy(n), decay(n);
    for (int i = 0; i < n; i++) {
        cin >> eat[i] >> energy[i] >> decay[i];
    } 
    // Greedy
    vector<bool> eaten(n, false);
    vector<int> curenergy = energy;
    ll score = 0;
    for (int i = 0; i < n; i++) {
        // select which one to eat
        int c;
        ll minloss = INT_MAX;
        // cout << "LOSS ";
        for (int j = 0; j < n; j++) {
            if (eaten[j]) continue;
            int s = eat[j];
            ll loss = 0;
            for (int k = 0; k < n; k++) {
                if (eaten[k] || k == j) continue;
                loss += min(curenergy[k], decay[k] * s);
            }
            // cout << loss << " ";
            if (loss < minloss) {
                minloss = loss;
                c = j;
            }
        }
        // cout << endl;
        // c will now be eaten, update curenergy;
        eaten[c] = true;
        score += curenergy[c];
        for (int j = 0; j < n; j++) { // update
            if (eaten[j]) continue;
            curenergy[j] = max(0, curenergy[j] - decay[j] * eat[c]);
        }
        curenergy[c] = 0;
        // cout << c << endl;
        // for (int i = 0; i < n; i++) {
        //     cout << curenergy[i] << " ";
        // }
        // cout << endl;
    }
    cout << "Case #" << t << ": " << score << endl;
}

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        sherlock(i);
    }
}