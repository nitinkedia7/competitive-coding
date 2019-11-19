#include <bits/stdc++.h>
using namespace std;

int main() {
    set<int> s = {3,2,4,1};
    set<int>::iterator i = s.begin();
    while (i != s.end()) {
        cout << *i << endl;
        i++;
    } 
    return 0;
}