#include <iostream>
#include <vector>
using namespace std;

int main() {
  int p = 1, pp = 1;
  int n;
  cin >> n;
  vector<int> v;
  while (p <= n) {
    v.push_back(p);
    int temp = pp + p;
    pp = p;
    p = temp;
  }
  // for (int i = 0; i < v.size(); i++) {
  //   cout << v[i] << " ";
  // }
  // cout << endl;
  int j = 0;
  for (int i = 1; i <= n; i++) {
    if (i == v[j]) {
      cout << "O";
      j++;
    }
    else cout << "o";
  }
  cout << endl;
}
