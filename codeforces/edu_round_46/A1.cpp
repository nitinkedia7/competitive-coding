#include <iostream>
#include <algorithm>
using namespace std;
 
int main() {
    int n;
    cin >> n;
    int a[9], b[9];

    for (int i = 0; i < 9; i++) {
        a[i] = 0;
        b[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (s == "M") a[0]++;
        else if (s == "S") a[1]++;
        else if (s == "L") a[2]++;
        else if (s == "XS") a[3]++;
        else if (s == "XL") a[4]++;
        else if (s == "XXS") a[5]++;
        else if (s == "XXL") a[6]++;
        else if (s == "XXXS") a[7]++;
        else if (s == "XXXL") a[8]++;
    }
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (s == "M") a[0]--;
        else if (s == "S") a[1]--;
        else if (s == "L") a[2]--;
        else if (s == "XS") a[3]--;
        else if (s == "XL") a[4]--;
        else if (s == "XXS") a[5]--;
        else if (s == "XXL") a[6]--;
        else if (s == "XXXS") a[7]--;
        else if (s == "XXXL") a[8]--;
    }
    int minsec = 0, maxsec = 0;
    for (int i = 0;i < 9; i++) {
        if (a[i] > 0) minsec += a[i];
        else maxsec += a[i];
    }
    cout << minsec << endl;

    return 0;
}