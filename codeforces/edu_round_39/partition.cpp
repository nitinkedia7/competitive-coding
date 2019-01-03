#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  int b = 0, c = 0, num;
  for (int i = 0; i < n; i++) {
    cin >> num;
    if (num > 0) b += num;
    else c += num;
  }
  cout << b-c << endl;
}
