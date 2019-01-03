#include <iostream>

using namespace std;

typedef unsigned long long ull;

bool perfect_square(int x) {
  if (x < 0) return false;
  int s = 0;
  while (s*s < x) s++;
  if (s*s == x) return true;
  return false;
}

int main() {
  int n;
  cin >> n;
  int array[n];
  for (int i = 0; i < n; i++) {
    cin >> array[i];
  }

  int nps = -1000001;
  int x;
  for (int i = 0; i < n; i++) {
    x = array[i];
    if (x > nps) {
      if (!perfect_square(x)) nps = x;
    }
  }
  cout << nps << endl;
}
