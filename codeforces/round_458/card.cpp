#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;

  int max = 0, max_count = 0, x;
  for (int i = 0; i < n; i++) {
    cin >> x;
    if (max < x) {
      max = x;
      max_count = 1;
    }
    else if (max == x) max_count++;
  }
  if (max_count%2 == 0) cout << "Agasa" << endl;
  else cout << "Conan" << endl;
}
