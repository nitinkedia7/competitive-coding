#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    char matrix[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    } 
    int count[m];
    for (int i = 0; i < m; i++) {
        count[i] = 0;
    }  
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            count[j] += matrix[i][j]-'0';           
        }
    }
    // count hai
    for (int k = 0; k < n; k++) {
        int count1[m];
        for (int i = 0; i < m; i++) {
            count1[i] = count[i] - (matrix[k][i]-'0');
        }
        for (int i = 0; i < m; i++) {
            if (count1[i] == 0) {
                break;
            }
            if (i == m-1) {
                cout << "YES" << endl;
                return 0;
            }
        }
    } 
    cout << "NO" << endl; 
}