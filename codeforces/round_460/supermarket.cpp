#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  long double a, b;
  cin >> a >> b;
  long double c, min = a/b;
  // cout << min << endl;
  for (int i = 1; i < n; i++) {
    cin >> a >> b;
    c = a/b;
    if (min > c) min = c;
  }
  printf("%Lf", m*min);
}
