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
        int n, m;
        cin >> n >> m;
        if (n == 1 && m == 1) {
            cout << 1 << endl;
            cout << 1 << endl;
        }
        else if (n == 1 && m == 2) {
            cout << 1 << endl;
            cout << 1 << " " << 1 << endl;
        }
        else if (n == 2 && m == 1) {
            cout << 1 << endl;
            cout << 1 << endl;
            cout << 1 << endl;
        }
        else if (n == 1) {
            cout << 2 << endl;
            for (int j = 0; j < m; j++) {
                if (j % 4 == 0) cout << 1;
                if (j % 4 == 1) cout << 1;
                if (j % 4 == 2) cout << 2;
                if (j % 4 == 3) cout << 2;
                if (j != m-1) cout << " ";
            }
            cout << endl;
        } 
        else if (m == 1) {
            cout << 2 << endl;
            for (int i = 0; i < n; i++) {
                if (i % 4 == 0) cout << 1;
                if (i % 4 == 1) cout << 1;
                if (i % 4 == 2) cout << 2;
                if (i % 4 == 3) cout << 2;
                cout << endl;  
            }
        }
        else if (n == 2 && m == 2) {
            cout << 2 << endl;
            cout << 1 << " " << 1 << endl;
            cout << 2 << " " << 2 << endl;
        }
        else if (n == 2) {
            cout << 3 << endl;
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < m; j++) {
                    if (j % 3 == 0) cout << 1;
                    if (j % 3 == 1) cout << 2;
                    if (j % 3 == 2) cout << 3;
                    cout << " ";
                }
                cout << endl;
            }
        }
        else if (m == 2) {
            cout << 3 << endl;
            for (int i = 0; i < n; i++) {
                if (i % 3 == 0) cout << "1 1" << endl;
                if (i % 3 == 1) cout << "2 2" << endl;
                if (i % 3 == 2) cout << "3 3" << endl;
            }
        }
        else {
            cout << 4 << endl;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (i % 4 == 0) {
                        if (j % 4 == 0) cout << 1;
                        if (j % 4 == 1) cout << 1;
                        if (j % 4 == 2) cout << 2;
                        if (j % 4 == 3) cout << 2;
                    }
                    if (i % 4 == 2) {
                        if (j % 4 == 0) cout << 2;
                        if (j % 4 == 1) cout << 2;
                        if (j % 4 == 2) cout << 1;
                        if (j % 4 == 3) cout << 1;  
                    }
                    if (i % 4 == 1) {
                        if (j % 4 == 0) cout << 3;
                        if (j % 4 == 1) cout << 3;
                        if (j % 4 == 2) cout << 4;
                        if (j % 4 == 3) cout << 4;
                    }
                    if (i % 4 == 3) {
                        if (j % 4 == 0) cout << 4;
                        if (j % 4 == 1) cout << 4;
                        if (j % 4 == 2) cout << 3;
                        if (j % 4 == 3) cout << 3;  
                    }
                    if (j != m-1) cout << " ";
                }
                cout << endl;
            }
        }
    }
}
