#include <iostream>
#include <random>
using namespace std;

int main() {
  int n;
  cin >> n;
  cout << n << endl;
  srand(time(NULL));
  for (int i = 0; i < n; i++) {
    cout << rand() % 1000000000 + 1 << " ";
  }
  cout << endl;
  int q;
  cin >> q;
  cout << q;
  for (int i = 0; i < q; i++) {
    if (i % (q/1000) == 0) {
      cout << "2 " << rand() % n-1 + 1 <<  " " << rand() % 1000000000 + 1 << endl;
    }
    else {
      int k = rand() % n-1 + 1;
      cout << "1 " << rand() % n-1 + k << " " << rand() % k + 1 << " " << rand() % 100000000 + 1 << endl;
    }
  }

}
