#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

void print(vector<int> &v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

void sherlock(int t) {
    int p, q;
    cin >> p >> q;
    vector<int> ver(q + 2, 0), hor(q + 2, 0);
    int x, y;
    char d;
    for (int i = 0; i < p; i++) {
        cin >> x >> y >> d;
        switch (d) {
            case 'N':
                ver[y + 1]++;
                ver[q + 1]--;
                break;
            case 'S':
                ver[0]++;
                ver[y]--;
                break;
            case 'E':
                hor[x + 1]++;
                hor[q + 1]--;
                break;
            case 'W':
                hor[0]++;
                hor[x]--;
                break;
            default:
                cout << "Invalid direction" << endl;
                break;
        }
    }

    for (int i = 1; i < q + 2; i++) {
        hor[i] += hor[i-1];
        ver[i] += ver[i-1];
    }
    // print(hor);
    // print(ver);
    int xmax = 0, ymax = 0; 
    for (int i = 0; i <= q; i++) {
        if (hor[i] > hor[xmax]) xmax = i;
        if (ver[i] > ver[ymax]) ymax = i;        
    }
    cout << "Case #" << t << ": " << xmax << " " << ymax << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}