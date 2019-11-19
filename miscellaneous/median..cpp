#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

multiset<int, greater<int>> maxh;
multiset<int> minh;
int k;

void insert(int x) {
    k++;
    minh.insert(x);
    x = *minh.begin();
    minh.erase(minh.begin());
    maxh.insert(x);

    if (k % 2 == 1) {
        if (maxh.size() != minh.size() + 1) {
            minh.insert(*maxh.begin());
            maxh.erase(maxh.begin());
        }
    }
    else {
        if (maxh.size() != minh.size()) {
            minh.insert(*maxh.begin());
            maxh.erase(maxh.begin());
        }
    }
    assert(maxh.size() + minh.size() == k);
}


void remove(int x) {
    if (k % 2 == 0) {
        if (x > *maxh.begin()) {
            // remove from minh;
            minh.erase(minh.find(x));
        }
        else {
            maxh.erase(maxh.find(x));
            maxh.insert(*minh.begin());
            minh.erase(minh.begin());
        }
    }
    else {
        if (x > *maxh.begin()) {
            minh.erase(minh.find(x));
            minh.insert(*maxh.begin());
            maxh.erase(maxh.begin());
        }
        else {
            maxh.erase(maxh.find(x));
        }
    }
    k--;
}

int findMedian() {
    if (k % 2 == 0) {
        return *maxh.begin() + *minh.begin();
    }
    return 2 * *maxh.begin();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    k = 0;
    for (int i = 0; i < n; i++) {
        insert(v[i]);
        cout << findMedian() << " ";
    }
    cout << endl;
    return 0;
}