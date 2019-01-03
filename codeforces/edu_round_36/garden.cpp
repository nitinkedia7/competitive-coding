#include <iostream>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  int b;
  int selected_bucket = 1;
  for (int i = 0; i < n; i++) {
    cin >> b;
    if (k % b == 0) {
      if (selected_bucket < b) selected_bucket = b;
    }
  }
  cout << k/selected_bucket << endl;
}
