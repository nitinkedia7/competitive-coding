#include <iostream>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  int msg1[n], msg2[m];
  for (int i = 0; i < n; i++) cin >> msg1[i];
  for (int i = 0; i < m; i++) cin >> msg2[i];
  int f = 0, s1 = 0, s2 = 0, i = 0, j = 0;
  while (i < n && j < m) {
    s1 += msg1[i++];
    s2 += msg2[j++];
    while(s1 != s2) {
      if (s1 < s2) s1 += msg1[i++];
      else s2 += msg2[j++];
    }
    //cout << s1 << " " << s2 << endl;
    f++;
  }
  cout << f << endl;
}
