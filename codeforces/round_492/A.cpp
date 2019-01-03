#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int b100 = n/100;
    n = n%100;
    int b20 = n/20;
    n = n%20;
    int b10 = n/10;
    n = n%10;
    int b5 = n/5;
    n = n%5;
    cout << b100 + b20 + b10 + b5 + n << endl;
}