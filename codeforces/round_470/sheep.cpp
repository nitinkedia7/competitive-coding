#include <iostream>
using namespace std;

int main() {
  int r, c;
  cin >> r >> c;

  char pasture[r][c];
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) cin >> pasture[i][j];
  }
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
        if (pasture[i][j] == 'S') {
          if (i > 0) {
            if (pasture[i-1][j] == 'W') {
              cout << "No" << endl;
              return 0;
            }
            else if (pasture[i-1][j] == '.') pasture[i-1][j] = 'D';
          }
          if (i < r-1) {
            if (pasture[i+1][j] == 'W') {
              cout << "No" << endl;
              return 0;
            }
            else if (pasture[i+1][j] == '.') pasture[i+1][j] = 'D';
          }
          if (j > 0) {
            if (pasture[i][j-1] == 'W') {
              cout << "No" << endl;
              return 0;
            }
            else if (pasture[i][j-1] == '.') pasture[i][j-1] = 'D';
          }
          if (j < c-1) {
            if (pasture[i][j+1] == 'W') {
              cout << "No" << endl;
              return 0;
            }
            else if (pasture[i][j+1] == '.') pasture[i][j+1] = 'D';
          }
        }
    }
  }
  cout << "Yes" << endl;
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      cout << pasture[i][j];
    }
    cout << endl;
  }
}
