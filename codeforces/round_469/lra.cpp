#include <iostream>
using namespace std;

int main() {
  int l, r, a;
  cin >> l >> r >> a;
  if (l > r) {
    int temp = l;
    l = r;
    r = temp;
  }
  int t = l;
  if (a <= r-l) t += a;
  else {
    int diff = r-l;
    t += diff + (a-diff)/2;
  }
  cout << 2*t << endl;
}
