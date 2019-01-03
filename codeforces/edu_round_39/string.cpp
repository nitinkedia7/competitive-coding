#include <iostream>
using namespace std;

int main() {
  string str;
  cin >> str;
  int l = str.length();
  char cc = 'a';
  for (int i = 0; i < l; i++) {
    if (str[i] <= cc) {
      str[i] = cc;
      if (cc == 'z') {
          cc = '1';
      }
      else cc += 1;
    }
  }
  if (cc == '1') cout << str << endl;
  else cout << -1 << endl;
}
