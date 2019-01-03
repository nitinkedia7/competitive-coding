#include <iostream>
using namespace std;

// // int gcd(int a, int b) {
// //   if (b == 0) return a;
// //   return gcd(b, a % b);
// // }
// int gcd(int a, int b) {
//   int temp;
//   while (b > 0) {
//     temp = a % b;
//     a = b;
//     b = temp;
//   }
//   return a;
// }

void almost_correct(int *array, int l, int r, int x) {
  int div_x = 0;
  for (int i = l-1; i < r; i++) {
    if (array[i] % x != 0) {
      div_x++;
      if (div_x > 1) {
        cout << "NO" << endl;
        return;
      }
    }
  }
  cout << "YES" << endl;
}

int main() {
  int n;
  cin >> n;
  int array[n];
  for (int i = 0; i < n; i++) {
    cin >> array[i];
  }

  int q;
  cin >> q;
  int type;
  for (int i = 0; i < q; i++) {
    cin >> type;
    if (type == 1) {
      int l, r, x;
      cin >> l >> r >> x;
      almost_correct(array, l, r, x);
    }
    else {
      int pos;
      cin >> pos;
      cin >> array[pos-1]; // array is 1 indexed
    }
  }
}
