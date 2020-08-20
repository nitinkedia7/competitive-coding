#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;

struct Rectangle {
    bool valid;
    int x1, y1, x2, y2;
    Rectangle(bool _valid, int _x1, int _y1, int _x2, int _y2) :
        valid(_valid), x1(_x1), y1(_y1), x2(_x2), y2(_y2) {}
    Rectangle() {} 
};

Rectangle intersection(Rectangle &A, Rectangle &B) {
    Rectangle I = *new Rectangle;
    if (A.valid == false || B.valid == false) {
        I.valid = false;
        return I; 
    }
    if (A.x2 <= B.x1 || B.x2 <= A.x1) {
        I.valid = false;
        return I; 
    }
    if (A.y2 <= B.y1 || B.y2 <= A.y1) {
        I.valid = false;
        return I ;
    }
    I.valid = true;
    I.x1 = max(A.x1, B.x1);
    I.x2 = min(A.x2, B.x2);
    I.y1 = max(A.y1, B.y1);
    I.y2 = min(A.y2, B.y2);
    return I;
}

ll area(Rectangle &A) {
    if (A.valid == false) {
        return 0;
    }
    return (A.x2 - A.x1) * 1LL * (A.y2 - A.y1);
}

void sherlock(int t) {
    Rectangle A = *new Rectangle();
    Rectangle B = *new Rectangle();
    Rectangle C = *new Rectangle();
    A.valid = true;
    B.valid = true;
    C.valid = true;
    cin >> A.x1 >> A.y1 >> A.x2 >> A.y2;
    cin >> B.x1 >> B.y1 >> B.x2 >> B.y2;
    cin >> C.x1 >> C.y1 >> C.x2 >> C.y2;
    ll size = area(A);
    Rectangle X = intersection(A, B); 
    size -= area(X);
    Rectangle Y = intersection(A, C); 
    size -= area(Y);
    Rectangle Z = intersection(X, Y);
    size += area(Z);
    // cout << size << endl;
    cout << (size > 0 ? "YES" : "NO") << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    // cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}
