#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

char query(int i) {
    cout << i << endl;
    char res;
    cin >> res;
    if (res == 'N') exit(0);
    return res;
}

void watson(int t) {
    vector<int> hideouts;
    for (int i = 1; i <= 595; i += 5) {
        hideouts.push_back(i);
    }
    unordered_map<char, vector<int>> pos;
    string ans;
    vector<int> magicnum = {23, 5, 1, 1};
    vector<bool> found(5, false);
    char c;

    // find characters one by one from msb to lsb
    for (int k = 0; k < 4; k++) {
        pos.clear();
        assert(hideouts.size() > 0);
        for (int i = 0; i < hideouts.size(); i++) {
            c = query(hideouts[i]);
            // cerr << c << endl;
            assert (c >= 'A' && c <= 'E');
            pos[c].push_back(hideouts[i]);
        }
        // cerr << endl;
        for (auto it = pos.begin(); it != pos.end(); it++) {
            // cerr << k << " " << it->first << " " << it->second.size() << endl;
            if ((it->second).size() == magicnum[k]) {
                ans.push_back(it->first);
                found[it->first - 'A'] = 1;
                hideouts.clear();
                for (auto x : it->second) {
                    hideouts.push_back(x + 1);
                }
                // hideouts = it->second;
            } 
        }
        // cerr << endl;
    }
    // cerr << "hi" << ans << endl;
    assert(ans.length() == 4);
    for (int i = 0; i < 5; i++) {
        if (!found[i]) {
            char last = ans[3];
            ans.pop_back();
            ans.push_back('A' + i);
            ans.push_back(last);
        }
    }
    cout << ans << endl;
    char res;
    cin >> res;
    if (res == 'N') exit(0);
    return;
}

void sherlock(int t) {
    watson(t);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt, f;
    cin >> tt >> f;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}