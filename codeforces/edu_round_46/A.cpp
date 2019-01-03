#include <iostream>
#include <algorithm>
using namespace std;

int findsec(string a, string b) {
    int l = a.length();
    int sec = 0;
    for (int i = 0; i < l; i++) {
        if (a[i] != b[i]) sec++;
    }
    return sec;
}
 
int main() {
    int n;
    cin >> n;
    string a[n], b[n];

    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    sort(a, a+n);
    sort(b, b+n);

    int minsec = 0;
    for (int i = 0; i < n; i++) {
        minsec += findsec(a[i], b[i]);
    }
    cout << minsec << endl;
    return 0;
}