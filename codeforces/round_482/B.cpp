#include <iostream>
#include <algorithm>
using namespace std;

int ascii(char c) {
    if (c >= 'a' && c <= 'z') {
        return (c-'a')+26;
    }
    else return (c-'A');
}

int func(int m, int l, int n) {
    if ((l-m) < n) {
        return l;
    }
    else return m+n; // just able to cover l
}
int main() {
    int n;
    int l;
    cin >> n;
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    l = s1.length();
    if (n >= (l-1)) {
        cout << "Draw" << endl;
        return 0;
    }
    else {
        int matrix[3][52];
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 52; j++) {
                matrix[i][j] = 0;
            }
        }
        for (int i = 0; i < l; i++) {
            matrix[0][ascii(s1[i])] += 1;
        }
        for (int i = 0; i < l; i++) {
            matrix[1][ascii(s2[i])] += 1;
        }
        for (int i = 0; i < l; i++) {
            matrix[2][ascii(s3[i])] += 1;
        }
        int m1 = *max_element(matrix[0], matrix[0]+52);
        int m2 = *max_element(matrix[1], matrix[1]+52);
        int m3 = *max_element(matrix[2], matrix[2]+52);
        // cout << m1 << " " << m2 << " " << m3 << endl;        
        m1 = func(m1, l, n);
        m2 = func(m2, l, n);
        m3 = func(m3, l, n);
        // cout << m1 << " " << m2 << " " << m3 << endl;
        if (m2 > m1) {
            if (m3 > m2) cout << "Katie" << endl;
            else if (m3 < m2) cout << "Shiro" << endl;
            else cout << "Draw" << endl;            
        }
        else if (m2 < m1) {
            if (m3 > m1) cout << "Katie" << endl;
            else if (m3 < m1) cout << "Kuro" << endl;
            else cout << "Draw" << endl;
        }
        else {
            if (m3 > m2) cout << "Katie" << endl;
            else cout << "Draw" << endl;
        }
        return 0;
    }
}