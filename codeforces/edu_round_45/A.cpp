#include <iostream>
using namespace std;

int main() {
    unsigned long long int n, m;
    int a, b;

    cin >> n >> m >> a >> b;

    unsigned long long int demo, build, diff;

    if (n % m == 0) {
        cout << "0" << endl;
        return 0;
    }   
    else {
        diff = n - (n/m)*m;
        demo = diff*b;
        build = (m-diff)*a;
        if (demo < build) {
            cout << demo << endl;
        }
        else {
            cout << build << endl;
        }
    }
}