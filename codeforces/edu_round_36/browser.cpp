#include <iostream>
using namespace std;

int main() {
  int n, pos, l, r;
  cin >> n >> pos >> l >> r;
  int time = 0;
  if (pos <= l) {
    time += (l-pos);
    if (l > 1) time++;
    if (r < n) {
      time += r-l;
      time++;
    }
  }
  else if (pos >= r) {
    time += (pos-r);
    if (r < n) time++;
    if (l > 1) {
      time += r-l;
      time++;
    }
  }
  else {
    if (r-pos > pos-l) {
      if (l > 1) {
        time += (pos-l);
        time++;
      }
      if (r < n) {
        time += r-l;
        time++;
      }
    }
    else {
      if (r < n) {
        time += (r-pos);
        time++;
      }
      if (l > 1) {
        time += r-l;
        time++;
      }
    }
  }
  cout << time << endl;
}
