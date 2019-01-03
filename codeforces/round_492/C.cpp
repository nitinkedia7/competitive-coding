#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    int array[2*n];
    int s = 0;
    for (int i = 0; i < 2*n; i++) cin >> array[i];
    int a[n+1][2];
    for (int i = 0; i <= n; i++) {
        a[i][0] = -1;
        a[i][1] = -1;
    }
    for (int i = 0; i < 2*n; i++) {
        if (a[array[i]][0] == -1) a[array[i]][0] = i;
        else a[array[i]][1] = i;
    }
    int temp = 0;
    while (temp < n) {
        for (int i = 1; i <= n; i++) {
            cout << a[i][0] << " " << a[i][1] << endl;
        }
        int md = 1;
        for (int i = 1; i <= n; i++) {
            int diff1 = a[i][1]-a[i][0];
            int diff2 = a[md][1]-a[md][0];
            if (diff2 == 1) {
                md = i;
            }
            else if (diff1 < diff2 && diff1 != 1) {
                md = i;
            }  
        }
        // cout << "md = " << md << endl;
        if (a[md][1] == a[md][0] + 1) break;
        int l = 0, r = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i][0] < a[md][0] && a[md][0] < a[i][1] && a[i][1] < a[md][1]) l++;
            else if (a[md][0] < a[i][0] && a[i][0] < a[md][1] && a[md][1] < a[i][1]) r++;
        }
        
        cout << s << endl;
        s += a[md][1] - a[md][0] - 1; 
        
        if (l < r) {
            for (int i = 1; i <= n; i++) {
                if (a[i][0] < a[md][0] && a[md][0] < a[i][1] && a[i][1] < a[md][1]) a[i][0] += 1;
                else if (a[md][0] < a[i][0] && a[i][0] < a[md][1] && a[md][1] < a[i][1]) a[i][1] += 1;
            }
            a[md][1] = a[md][0] + 1;
        }
        else {
            for (int i = 1; i <= n; i++) {
                if (a[i][0] < a[md][0] && a[md][0] < a[i][1] && a[i][1] < a[md][1]) a[i][0] -= 1;
                else if (a[md][0] < a[i][0] && a[i][0] < a[md][1] && a[md][1] < a[i][1]) a[i][1] -= 1;
            }
            a[md][0] = a[md][1] - 1;
        }
        // cout << temp << endl;
        temp++;
    }
    cout << s << endl;
}
