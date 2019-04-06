#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define popb pop_back
#define all(c) c.begin(),c.end()
#define mp make_pair
#define f first
#define s second
typedef long long ll;
typedef long double ld;
const int mod = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	cout.tie(nullptr);
    int t;
    cin >> t;
    for (; t > 0; t--) {
        int n, a, b;
        cin >> n >> a >> b;
        multiset<int> bob, al;
        int m = 0;
        for (int i = 0; i < n; i++) {
            int c;
            cin >> c;
            if (c % a == 0) bob.insert(c);
            if (c % b == 0) al.insert(c);
            if (c % a == 0 && c % b == 0) m++;
        }
        int x = bob.size(), y = al.size();
        if (m == 0) {
            if (x == 0) {
                cout << "ALICE" << endl;
                continue; 
            }
            if (y == 0) {
                cout << "BOB" << endl;
                continue; 
            }
            if (x > y) {
                cout << "BOB" << endl;
                continue; 
            }
            else if (x == y) {
                cout << "ALICE" << endl;
                continue;     
            }
            else {
                cout << "ALICE" << endl;
                continue;  
            }
        }
        else if (x == m && y == m) {
            cout << "BOB" << endl;
            continue;  
        }
        else if (y == m) {
            cout << "BOB" << endl;
            continue; 
        }
        else  if (x == m) {
            cout << "ALICE" << endl;
            continue; 
        }
        else if (x > m && y > m) {
            if (x > y) {
                cout << "BOB" << endl;
                continue;
            }
            else if (x == y) {
                cout << "BOB" << endl;
                continue;
            }
            else {
                cout << "ALICE" << endl;
                continue;
            }
        }
    }
    return 0;
}