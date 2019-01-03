#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(string s1, string s2) {
    return (s1.length() < s2.length());
}

int main() {
    int n;
    cin >> n;

    string v[n];
    for (int i = 0; i < n; i++) cin >> v[i];

    sort(v, v+n, comp);    
    bool flag = true;
    for (int i = 1; i < n; i++) {
        if (v[i].find(v[i-1]) == string::npos) { // not substr
            flag = false;
            break;
        }
    }
    if (flag) {
        cout << "YES" << endl;
        for (int i = 0; i < n; i++) {
            cout << v[i] << endl;
        }
    }
    else cout << "NO" << endl;
 
}