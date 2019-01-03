#include <iostream>
using namespace std;

int digits(int *array, int a) {
  int i = 0;
  while (a > 0) {
    array[i] = a % 10;
    i++;
    a = a/10;
  }
  return i;
}

int main() {
  int a, b;
  cin >> a >> b;
  int array1[19], array2[19];
  int l1 = digits(array1, a);
  sort(array1, array1+l1);
  int l2 = digits(array2, b);
  if (l1 < l2) {
    for (int i = 0; i < l1; i++) {
      cout << array[i];
    }
    cout << endl;
  }
  else if (l1 == l2) {
    while ()
  }
}
