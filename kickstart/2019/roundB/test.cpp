#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v = {0, 2, 3, 6};
    vector<int>::iterator it;
    it = lower_bound(v.begin(), v.end(), 0);
    cout << it - v.begin() << endl;
    return 0;
}