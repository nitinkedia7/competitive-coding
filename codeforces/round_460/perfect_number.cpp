#include <bits/stdc++.h>
using namespace std;

int func(int k) {
  int mul = 1;
  int array[4];
  array[0] = 11;
  array[1] = 111;
  array[2] = 1111;
  array[3] = 11111;
  for (int i = 0; i < k; i++) {
    mul++;
    for (i = 0; i < 4; i++) {
      if (mul % array[i] == 0) {
        mul++;
        break;
      }
    }
  }
  return mul;
}

int main() {
  int k;
  cin >> k;
  int mul = func(k);
  printf("%d", 9*mul+1);
}
