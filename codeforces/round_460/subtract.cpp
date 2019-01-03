#include <iostream>
using namespace std;

unsigned long long function(unsigned long long n, unsigned long long m) {
  unsigned long long k = n/m;
  return k - k%2;
}

int main() {
  unsigned long long n, m, k;
  cin >> n >> m;
  while(n > 0 and m > 0) {
    if (n >= 2*m) {
      k = function(n, m);
      n -= k*m;
    }
    else if (m >= 2*n) {
      k = function(m, n);
      m -= k*n;
    }
    else break;
  }
  cout << n << " " << m << endl;
}
