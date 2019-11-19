#include <bits/stdc++.h>
using namespace std;

int mapi(int x) {
    switch (x) {
        case 1:
            return 0;
        case -2: 
            return 0;
        case 3:
            return 1;
        case -4:
            return -1;
        case 5:
            return 1;
        case -6:
            return -1;
        default:
            assert(false);
            return -1000;
    }
}

void print(vector<pair<int,int>> &v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i].first << "," << v[i].second << " ";
    }
    cout << endl;
}

bool func(int y1, int y2, int y3, int y4, int y5, int y6) {
    if (y3 < y1) {
        y3 = y1;
    }
    if (y4 > y2) {
        y4 = y2;
    }
    if (y5 < y1) {
        y5 = y1;
    }
    if (y6 > y2) {
        y6 = y2;
    }
    vector<pair<int,int>> v;
    v.push_back({y1, 1});
    v.push_back({y2, -2});
    if (y3 >= y1 && y4 <= y2) {
        v.push_back({y3, 3});
        v.push_back({y4, -4});
    }
    if (y5 >= y1 && y6 <= y2) {
        v.push_back({y5, 5});
        v.push_back({y6, -6});
    }


    sort(v.begin(), v.end());
    print(v);
    vector<int> val;
    int a = 0;
    for (int i = 0; i < v.size(); i++) {
        a += mapi(v[i].second);
        if (i != v.size() - 1 && v[i+1].first > v[i].first) {
            val.push_back(a);
        }
    }
    for (int i = 0; i < val.size(); i++) {
        if (val[i] == 0) {
            return true;
        }
    }
    return false;
}

int main() {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int x3, y3, x4, y4;
    cin >> x3 >> y3 >> x4 >> y4;
    int x5, y5, x6, y6;
    cin >> x5 >> y5 >> x6 >> y6;
    cout << func(y1, y2, y3, y4, y5, y6) << endl;
    cout << func(x1, x2, x3, x4, x5, x6) << endl;
    if (func(y1, y2, y3, y4, y5, y6) || func(x1, x2, x3, x4, x5, x6)) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
    return 0;
}