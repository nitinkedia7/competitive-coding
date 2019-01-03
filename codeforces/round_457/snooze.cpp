#include <iostream>
using namespace std;

bool lucky_check(int h, int m) {
        if (h%10 == 7 || m%10 == 7) return true;
        else return false;
}

int main() {
        int x, h, m;
        cin >> x >> h >> m;

        int y = 0;
        while (!lucky_check(h, m)) {
                if (m >= x) m = m-x;
                else {
                        if (h > 0) {
                                h--;
                        }
                        else {
                                h = 23;
                        }
                        m = m + 60 - x;
                }
                y++;
        }
        cout << y << endl;
        // cout << h  << " " << m << endl;
        return 0;
}
